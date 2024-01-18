"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.SolutionWriter = exports.ProjectWriter = exports.CMakeWriter = void 0;
const path_1 = require("path");
const lodash_1 = __importDefault(require("lodash"));
const concepts_1 = require("./concepts");
const document_1 = require("./document");
const cm = __importStar(require("./cmake"));
class CMakeWriter {
    constructor() { }
    write(context, solution_config, project_configs) {
        let project_path = this.get_project_path();
        if (lodash_1.default.isUndefined(project_path)) {
            return false;
        }
        let doc = new document_1.Document();
        doc.add(cm.cmake_minimum_required(context.cmake_minimum_required));
        this.update_cmake_lines(context, solution_config, project_configs, doc);
        doc.save(project_path);
        return true;
    }
    // pure virtual function
    get_project_path() {
        return;
    }
    // pure virtual function
    update_cmake_lines(context, solution_config, projects, doc) {
        return;
    }
}
exports.CMakeWriter = CMakeWriter;
class ProjectWriter extends CMakeWriter {
    constructor(project_config) {
        super();
        this.data = project_config;
    }
    get_project_path() {
        return this.data.project_path;
    }
    update_cmake_lines(context, solution_config, project_configs, doc) {
        doc.add(cm.project(this.data.name));
        doc.add(cm.cmake_include_current_dir(this.data.include_current_dir));
        let qt_config = this.data.qt_config;
        if (!lodash_1.default.isUndefined(qt_config)) {
            doc.add(cm.cmake_autouic(qt_config.auto_uic));
            doc.add(cm.cmake_autouic(qt_config.auto_moc));
            doc.add(cm.cmake_autouic(qt_config.auto_rcc));
        }
        if (this.data.type === concepts_1.ProjectType.DESKTOP_APPLICATION) {
            doc.add(cm.cmake_exe_linker_flags());
        }
        doc.add(cm.cmake_cxx_standard(this.data.cxx_standard));
        doc.add(cm.cmake_cxx_standard_required(this.data.cxx_standard_required));
        // collect including paths
        let include_directories = new Set();
        let project_full_path_str = this.data.project_path.toLocaleString();
        for (let file of this.data.files) {
            let file_path = (0, path_1.join)(project_full_path_str, file.toLocaleString());
            include_directories.add((0, path_1.dirname)(file_path));
        }
        for (let internal_library_name of this.data.internal_libraries) {
            if (lodash_1.default.has(project_configs, internal_library_name)) {
                let internal_library = project_configs[internal_library_name];
                if (internal_library.type == concepts_1.ProjectType.STATIC_LIBRARY ||
                    internal_library.type == concepts_1.ProjectType.DYNAMIC_LINK_LIBRARY) {
                    include_directories.add(internal_library.project_path);
                    for (let file_rel_path of internal_library.files) {
                        let file_full_path = (0, path_1.join)(project_full_path_str, file_rel_path.toLocaleString());
                        include_directories.add((0, path_1.dirname)(file_full_path));
                    }
                    let ext = (0, path_1.extname)(internal_library.target_filename);
                    let end = internal_library.target_filename.length - ext.length;
                    let lib_name = `${internal_library.target_filename.substring(0, end)}.lib`;
                    doc.add(cm.link_libraries(lib_name));
                }
            }
        }
        for (let include_directory of this.data.include_directories) {
            if ((0, path_1.isAbsolute)(include_directory)) {
                include_directories.add(include_directory);
            }
            else {
                let include_directory_path = (0, path_1.join)(this.data.project_path.toLocaleString(), include_directory);
                include_directories.add(include_directory_path);
            }
        }
        for (let include_directory of include_directories) {
            doc.add(cm.include_directories(include_directory));
        }
        for (let link_dir of this.data.link_directories) {
            let link_dir_path = (0, path_1.join)(this.data.project_path.toLocaleString(), link_dir);
            doc.add(cm.link_directories(link_dir_path));
        }
        for (let link_lib of this.data.link_libraries) {
            doc.add(cm.link_libraries(link_lib));
        }
        if (this.data.internal_libraries.length > 0) {
            let output_directory = (0, path_1.join)(solution_config.solution_path.toLocaleString(), solution_config.output_directory.toLocaleString());
            doc.add(cm.link_directories(output_directory));
        }
        if (!lodash_1.default.isUndefined(qt_config)) {
            for (let qt_package of qt_config.packages) {
                doc.add(cm.find_package_qt(qt_package));
            }
        }
        let project_sources_variable = 'PROJECT_SOURCES';
        doc.add(cm.set_variable_multi_paths(project_sources_variable, this.data.files));
        if (this.data.type == concepts_1.ProjectType.CONSOLE_APPLICATION || this.data.type == concepts_1.ProjectType.DESKTOP_APPLICATION) {
            doc.add(cm.add_executable(this.data.name, project_sources_variable));
        }
        if (this.data.type == concepts_1.ProjectType.STATIC_LIBRARY) {
            doc.add(cm.add_library(this.data.name, project_sources_variable));
        }
        if (this.data.type == concepts_1.ProjectType.DYNAMIC_LINK_LIBRARY) {
            doc.add(cm.add_library(this.data.name, project_sources_variable, true));
        }
        for (let file_rel_path of this.data.files) {
            doc.add(this.source_group(file_rel_path));
        }
        for (let definition of this.data.definitions) {
            doc.add(cm.target_compile_definitions(this.data.name, definition));
        }
        if (!lodash_1.default.isUndefined(qt_config)) {
            for (let qt_package of qt_config.packages) {
                doc.add(cm.target_link_libraries_qt(this.data.name, qt_package));
            }
        }
    }
    source_group(file_path) {
        let filter = (0, path_1.dirname)(file_path.toLocaleString());
        if (filter === '.') {
            filter = '';
        }
        return cm.source_group(filter, file_path);
    }
}
exports.ProjectWriter = ProjectWriter;
class SolutionWriter extends CMakeWriter {
    constructor(solution_config) {
        super();
        this.data = solution_config;
    }
    get_project_path() {
        return this.data.solution_path;
    }
    update_cmake_lines(context, solution_config, project_configs, lines) {
        lines.add(cm.project(this.data.name, this.data.version));
        lines.add(cm.cmake_output_directory(this.data.output_directory));
        for (let subdirectory of this.data.subdirectories) {
            lines.add(cm.add_subdirectory(subdirectory));
        }
        if (this.data.startup_project.length > 0) {
            lines.add(cm.startup_project(this.data.startup_project));
        }
        let debug_directory = this.data.debugger_working_directory.toLocaleString();
        if (debug_directory.length > 0) {
            lines.add(cm.debugger_working_directory(this.data.startup_project, this.data.debugger_working_directory));
        }
        for (let project_name in project_configs) {
            let project_config = project_configs[project_name];
            for (let internal_library of project_config.internal_libraries) {
                lines.add(cm.add_dependencies(project_name, internal_library));
            }
        }
    }
}
exports.SolutionWriter = SolutionWriter;
