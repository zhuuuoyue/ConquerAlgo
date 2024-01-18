"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.parse_solution_and_projects = void 0;
const fs_1 = require("fs");
const path_1 = require("path");
const lodash_1 = __importDefault(require("lodash"));
const concepts_1 = require("./concepts");
const constants_1 = require("./constants");
function is_array_of_string(data) {
    if (!lodash_1.default.isArray(data)) {
        return false;
    }
    for (let item of data) {
        if (!lodash_1.default.isString(item)) {
            return false;
        }
    }
    return true;
}
class ProjectParser {
    constructor(cmake_path) {
        this.name_key = 'name';
        this.type_key = 'type';
        this.target_filename_key = 'target_filename';
        this.definitions_key = 'definitions';
        this.include_current_directory_key = 'include_current_directory';
        this.cxx_standard_key = 'cxx_standard';
        this.include_directories_key = 'include_directories';
        this.link_directories_key = 'link_directories';
        this.link_libraries_key = 'link_libraries';
        this.internal_includes_key = 'internal_includes';
        this.internal_libraries_key = 'internal_libraries';
        this.qt_key = 'qt';
        this.qt_auto_uic_key = 'auto_uic';
        this.qt_auto_moc_key = 'auto_moc';
        this.qt_auto_rcc_key = 'auto_rcc';
        this.qt_packages_key = 'packages';
        this.qt_console_key = 'console';
        this.extensions_of_cxx = new Set();
        this.extensions_of_cxx.add('.h');
        this.extensions_of_cxx.add('.c');
        this.extensions_of_cxx.add('.i');
        this.extensions_of_cxx.add('.hpp');
        this.extensions_of_cxx.add('.cpp');
        this.extensions_of_cxx.add('.cc');
        this.extensions_of_cxx.add('.cxx');
        this.extensions_of_cxx.add('.c++');
        this.extensions_of_cxx.add('.hh');
        this.extensions_of_cxx.add('.hxx');
        this.extensions_of_cxx.add('.h++');
        this.extensions_of_cxx.add('.ii');
        this.extensions_of_qt = new Set();
        this.extensions_of_qt.add('.ui');
        this.extensions_of_qt.add('.qrc');
        this.cmake_path = cmake_path;
        this.project_path = (0, path_1.dirname)(this.cmake_path.toLocaleString());
        this.project_name = (0, path_1.basename)(this.project_path);
    }
    parse() {
        let content = (0, fs_1.readFileSync)(this.cmake_path).toLocaleString();
        let data = JSON.parse(content);
        let project_config = new concepts_1.ProjectConfig();
        project_config.project_path = this.project_path;
        if (!this.parse_name(data, project_config)) {
            return;
        }
        if (!this.parse_type(data, project_config)) {
            return;
        }
        if (!this.parse_qt_config(data, project_config)) {
            return;
        }
        if (!this.search_files(data, project_config)) {
            return;
        }
        if (!this.parse_target_filename(data, project_config)) {
            return;
        }
        if (!this.parse_definitions(data, project_config)) {
            return;
        }
        if (!this.parse_include_current_directory(data, project_config)) {
            return;
        }
        if (!this.parse_cxx_standard(data, project_config)) {
            return;
        }
        if (!this.parse_include_directories(data, project_config)) {
            return;
        }
        if (!this.parse_link_directories(data, project_config)) {
            return;
        }
        if (!this.parse_link_libraries(data, project_config)) {
            return;
        }
        if (!this.parse_internal_includes(data, project_config)) {
            return;
        }
        if (!this.parse_internal_libraries(data, project_config)) {
            return;
        }
        return project_config;
    }
    search_files(data, project_config) {
        project_config.files.push(constants_1.cmake_config_filename);
        let directories = [this.project_path];
        let is_qt_project = !lodash_1.default.isUndefined(project_config.qt_config);
        while (directories.length > 0) {
            let current_directory = directories.pop();
            if (lodash_1.default.isUndefined(current_directory)) {
                continue;
            }
            let children = (0, fs_1.readdirSync)(current_directory.toLocaleString());
            for (let child of children) {
                if (child === '.' || child === '..') {
                    continue;
                }
                let child_path = (0, path_1.join)(current_directory.toLocaleString(), child);
                let child_state = (0, fs_1.statSync)(child_path);
                if (child_state.isFile()) {
                    let ext = (0, path_1.extname)(child_path).toLowerCase();
                    let relative_path = (0, path_1.relative)(this.project_path.toLocaleString(), child_path);
                    if (this.extensions_of_cxx.has(ext)) {
                        project_config.files.push(relative_path);
                    }
                    else if (is_qt_project && this.extensions_of_qt.has(ext)) {
                        project_config.files.push(relative_path);
                    }
                }
                else if (child_state.isDirectory()) {
                    directories.push(child_path);
                }
            }
        }
        return true;
    }
    parse_name(data, project_config) {
        if (lodash_1.default.has(data, this.name_key) && lodash_1.default.isString(data[this.name_key])) {
            project_config.name = data[this.name_key];
        }
        if (project_config.name.length == 0) {
            project_config.name = this.project_name;
        }
        return project_config.name.length !== 0;
    }
    parse_type(data, project_config) {
        if (lodash_1.default.has(data, this.type_key)) {
            let project_type = data[this.type_key];
            if (lodash_1.default.isString(project_type)) {
                if (project_type == concepts_1.console_application) {
                    project_config.type = concepts_1.ProjectType.CONSOLE_APPLICATION;
                }
                else if (project_type == concepts_1.desktop_application) {
                    project_config.type = concepts_1.ProjectType.DESKTOP_APPLICATION;
                }
                else if (project_type == concepts_1.static_library) {
                    project_config.type = concepts_1.ProjectType.STATIC_LIBRARY;
                }
                else if (project_type == concepts_1.dynamic_link_library) {
                    project_config.type = concepts_1.ProjectType.DYNAMIC_LINK_LIBRARY;
                }
            }
        }
        return true;
    }
    parse_target_filename(data, project_config) {
        if (lodash_1.default.has(data, this.target_filename_key)) {
            project_config['target_filename'] = data[this.target_filename_key];
        }
        else {
            let t = project_config.type;
            if (t == concepts_1.ProjectType.CONSOLE_APPLICATION || t == concepts_1.ProjectType.DESKTOP_APPLICATION) {
                project_config.target_filename = `${project_config.name}.exe`;
            }
            else if (t == concepts_1.ProjectType.STATIC_LIBRARY) {
                project_config.target_filename = `${project_config.name}.lib`;
            }
            else if (t == concepts_1.ProjectType.DYNAMIC_LINK_LIBRARY) {
                project_config.target_filename = `${project_config.name}.dll`;
            }
        }
        return true;
    }
    parse_definitions(data, project_config) {
        if (lodash_1.default.has(data, this.definitions_key)) {
            if (is_array_of_string(data[this.definitions_key])) {
                project_config.definitions = data[this.definitions_key];
            }
        }
        return true;
    }
    parse_include_current_directory(data, project_config) {
        if (lodash_1.default.has(data, this.include_current_directory_key)) {
            let value = data[this.include_current_directory_key];
            if (lodash_1.default.isBoolean(value)) {
                project_config.include_current_dir = value;
            }
        }
        return true;
    }
    parse_cxx_standard(data, project_config) {
        if (lodash_1.default.has(data, this.cxx_standard_key)) {
            let value = data[this.cxx_standard_key];
            if (lodash_1.default.isInteger(value)) {
                if (value == concepts_1.cxx_11) {
                    project_config.cxx_standard = concepts_1.CxxStandard.CXX_11;
                }
                else if (value == concepts_1.cxx_14) {
                    project_config.cxx_standard = concepts_1.CxxStandard.CXX_14;
                }
                else if (value == concepts_1.cxx_17) {
                    project_config.cxx_standard = concepts_1.CxxStandard.CXX_17;
                }
                else if (value == concepts_1.cxx_20) {
                    project_config.cxx_standard = concepts_1.CxxStandard.CXX_20;
                }
            }
        }
        return true;
    }
    parse_include_directories(data, project_config) {
        if (lodash_1.default.has(data, this.include_directories_key)) {
            if (is_array_of_string(data[this.include_directories_key])) {
                project_config.include_directories = data[this.include_directories_key];
            }
        }
        return true;
    }
    parse_link_directories(data, project_config) {
        if (lodash_1.default.has(data, this.link_directories_key)) {
            if (is_array_of_string(data[this.link_directories_key])) {
                project_config.link_directories = data[this.link_directories_key];
            }
        }
        return true;
    }
    parse_link_libraries(data, project_config) {
        if (lodash_1.default.has(data, this.link_libraries_key)) {
            if (is_array_of_string(data[this.link_libraries_key])) {
                project_config.link_libraries = data[this.link_libraries_key];
            }
        }
        return true;
    }
    parse_internal_includes(data, project_config) {
        if (lodash_1.default.has(data, this.internal_includes_key)) {
            let value = data[this.internal_includes_key];
            if (is_array_of_string(value)) {
                project_config.internal_includes = value;
            }
        }
        return true;
    }
    parse_internal_libraries(data, project_config) {
        if (lodash_1.default.has(data, this.internal_libraries_key)) {
            let value = data[this.internal_libraries_key];
            if (is_array_of_string(value)) {
                project_config.internal_libraries = value;
            }
        }
        return true;
    }
    parse_qt_config(data, project_config) {
        if (lodash_1.default.has(data, this.qt_key)) {
            let qt_object = data[this.qt_key];
            if (lodash_1.default.isObject(qt_object)) {
                let qt_config = new concepts_1.QtProjectConfig();
                if (lodash_1.default.has(qt_object, this.qt_auto_uic_key)) {
                    let value = qt_object[this.qt_auto_uic_key];
                    if (lodash_1.default.isBoolean(value)) {
                        qt_config.auto_uic = value;
                    }
                }
                if (lodash_1.default.has(qt_object, this.qt_auto_moc_key)) {
                    let value = qt_object[this.qt_auto_moc_key];
                    if (lodash_1.default.isBoolean(value)) {
                        qt_config.auto_moc = value;
                    }
                }
                if (lodash_1.default.has(qt_object, this.qt_auto_rcc_key)) {
                    let value = qt_object[this.qt_auto_rcc_key];
                    if (lodash_1.default.isBoolean(value)) {
                        qt_config.auto_rcc = value;
                    }
                }
                if (lodash_1.default.has(qt_object, this.qt_packages_key)) {
                    let value = qt_object[this.qt_packages_key];
                    if (is_array_of_string(value)) {
                        qt_config.packages = value;
                    }
                }
                if (lodash_1.default.has(qt_object, this.qt_console_key)) {
                    let value = qt_object[this.qt_console_key];
                    if (lodash_1.default.isBoolean(value)) {
                        qt_config.console = value;
                    }
                }
                project_config.qt_config = qt_config;
            }
        }
        return true;
    }
}
class SolutionParser {
    constructor(cmake_path) {
        this.name_key = 'name';
        this.output_directory_key = 'output_directory';
        this.startup_project_key = 'startup_project';
        this.debugger_working_directory_key = 'debugger_working_directory';
        this.cmake_path = cmake_path;
        this.solution_path = (0, path_1.dirname)(this.cmake_path.toLocaleString());
    }
    parse() {
        let content = (0, fs_1.readFileSync)(this.cmake_path).toLocaleString();
        let data = JSON.parse(content);
        let solution_config = new concepts_1.SolutionConfig();
        solution_config.solution_path = this.solution_path;
        if (!this.parse_name(data, solution_config)) {
            return;
        }
        if (!this.parse_output_directory(data, solution_config)) {
            return;
        }
        if (!this.parse_startup_project(data, solution_config)) {
            return;
        }
        if (!this.parse_debugger_working_directory(data, solution_config)) {
            return;
        }
        return solution_config;
    }
    parse_name(data, solution_config) {
        if (lodash_1.default.has(data, this.name_key)) {
            let value = data[this.name_key];
            if (lodash_1.default.isString(value)) {
                solution_config.name = value;
            }
        }
        return solution_config.name.length > 0;
    }
    parse_output_directory(data, solution_config) {
        if (lodash_1.default.has(data, this.output_directory_key)) {
            let value = data[this.output_directory_key];
            if (lodash_1.default.isString(value) && value.length > 0) {
                solution_config.output_directory = value;
            }
        }
        return true;
    }
    parse_startup_project(data, solution_config) {
        if (lodash_1.default.has(data, this.startup_project_key)) {
            let value = data[this.startup_project_key];
            if (lodash_1.default.isString(value) && value.length > 0) {
                solution_config.startup_project = value;
            }
        }
        return true;
    }
    parse_debugger_working_directory(data, solution_config) {
        if (lodash_1.default.has(data, this.debugger_working_directory_key)) {
            let value = data[this.debugger_working_directory_key];
            if (lodash_1.default.isString(value)) {
                solution_config.debugger_working_directory = value;
            }
        }
        return true;
    }
}
function parse_solution_and_projects(solution_cmake_path, project_cmake_paths) {
    let solution_parser = new SolutionParser(solution_cmake_path);
    let solution = solution_parser.parse();
    if (lodash_1.default.isUndefined(solution)) {
        return;
    }
    let projects = {};
    for (let project_cmake_path of project_cmake_paths) {
        let project_parser = new ProjectParser(project_cmake_path);
        let project_config = project_parser.parse();
        if (!lodash_1.default.isUndefined(project_config)) {
            solution.subdirectories.push(project_config.name);
            projects[project_config.name] = project_config;
        }
    }
    return {
        solution_config: solution,
        project_configs: projects,
    };
}
exports.parse_solution_and_projects = parse_solution_and_projects;
