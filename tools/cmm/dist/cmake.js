"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.add_dependencies = exports.debugger_working_directory = exports.startup_project = exports.set_variable_multi_paths = exports.cmake_exe_linker_flags = exports.cmake_output_directory = exports.cmake_cxx_standard_required = exports.cmake_cxx_standard = exports.cmake_autorcc = exports.cmake_automoc = exports.cmake_autouic = exports.cmake_include_current_dir = exports.add_subdirectory = exports.target_link_libraries_qt = exports.find_package_qt = exports.source_group = exports.add_executable = exports.add_library = exports.target_compile_definitions = exports.link_directories = exports.include_directories = exports.link_libraries = exports.project = exports.cmake_minimum_required = void 0;
const lodash_1 = __importDefault(require("lodash"));
const concepts_1 = require("./concepts");
function str(value) {
    return `"${value}"`;
}
function path_to_string(file_path) {
    let file_path_str = file_path.toLocaleString();
    let old_value = new RegExp('\\\\', 'g');
    return file_path_str.replace(old_value, '/');
}
function cmake_minimum_required(version) {
    return `cmake_minimum_required(VERSION ${version})`;
}
exports.cmake_minimum_required = cmake_minimum_required;
function project(name, version) {
    if (lodash_1.default.isUndefined(version)) {
        return `project(${str(name)} LANGUAGES CXX)`;
    }
    else {
        return `project(${str(name)} VERSION ${version} LANGUAGES CXX)`;
    }
}
exports.project = project;
function link_libraries(lib) {
    if (lib.length > 0) {
        return `link_libraries(${str(lib)})`;
    }
}
exports.link_libraries = link_libraries;
function include_directories(dir) {
    return `include_directories(${path_to_string(dir)})`;
}
exports.include_directories = include_directories;
function link_directories(dir) {
    return `link_directories(${path_to_string(dir)})`;
}
exports.link_directories = link_directories;
function target_compile_definitions(name, definition) {
    return `target_compile_definitions(${str(name)} PRIVATE ${definition})`;
}
exports.target_compile_definitions = target_compile_definitions;
function add_library(project_name, file_list_var, shared) {
    if (!lodash_1.default.isUndefined(shared) && shared) {
        return `add_library(${str(project_name)} SHARED \${${file_list_var}})`;
    }
    else {
        return `add_library(${str(project_name)} \${${file_list_var}})`;
    }
}
exports.add_library = add_library;
function add_executable(project_name, file_list_var) {
    return `add_executable(${str(project_name)} \${${file_list_var}})`;
}
exports.add_executable = add_executable;
function source_group(filter, file_path) {
    return `source_group(${str(path_to_string(filter))} FILES ${path_to_string(file_path)})`;
}
exports.source_group = source_group;
function find_package_qt(pkg) {
    return [
        `find_package(QT NAMES Qt6 Qt5 COMPONENTS ${pkg} REQUIRED)`,
        `find_package(Qt\${QT_VERSION_MAJOR} COMPONENTS ${pkg} REQUIRED)`,
    ];
}
exports.find_package_qt = find_package_qt;
function target_link_libraries_qt(name, pkg) {
    return `target_link_libraries(${str(name)} PRIVATE Qt\${QT_VERSION_MAJOR}::${pkg})`;
}
exports.target_link_libraries_qt = target_link_libraries_qt;
function add_subdirectory(subdir) {
    return `add_subdirectory(${str(subdir.toLocaleString())})`;
}
exports.add_subdirectory = add_subdirectory;
// set variables
function cmake_include_current_dir(value) {
    if (value) {
        return `set(CMAKE_INCLUDE_CURRENT_DIR ON)`;
    }
}
exports.cmake_include_current_dir = cmake_include_current_dir;
function cmake_autouic(value) {
    if (value) {
        return `set(CMAKE_AUTOUIC ON)`;
    }
}
exports.cmake_autouic = cmake_autouic;
function cmake_automoc(value) {
    if (value) {
        return `set(CMAKE_AUTOMOC ON)`;
    }
}
exports.cmake_automoc = cmake_automoc;
function cmake_autorcc(value) {
    if (value) {
        return `set(CMAKE_AUTORCC ON)`;
    }
}
exports.cmake_autorcc = cmake_autorcc;
function cmake_cxx_standard(value) {
    let value_str = '11';
    if (concepts_1.CxxStandard.CXX_11 === value) {
        value_str = '11';
    }
    else if (concepts_1.CxxStandard.CXX_14 === value) {
        value_str = '14';
    }
    else if (concepts_1.CxxStandard.CXX_17 === value) {
        value_str = '17';
    }
    else if (concepts_1.CxxStandard.CXX_20 === value) {
        value_str = '20';
    }
    return `set(CMAKE_CXX_STANDARD ${value_str})`;
}
exports.cmake_cxx_standard = cmake_cxx_standard;
function cmake_cxx_standard_required(value) {
    if (value) {
        return `set(CMAKE_CXX_STANDARD_REQUIRED ON)`;
    }
}
exports.cmake_cxx_standard_required = cmake_cxx_standard_required;
function cmake_output_directory(output_dir) {
    let output_dir_str = path_to_string(output_dir);
    return [
        `set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY \${CMAKE_SOURCE_DIR}/${output_dir_str})`,
        `set(CMAKE_LIBRARY_OUTPUT_DIRECTORY \${CMAKE_SOURCE_DIR}/${output_dir_str})`,
        `set(CMAKE_RUNTIME_OUTPUT_DIRECTORY \${CMAKE_SOURCE_DIR}/${output_dir_str})`,
    ];
}
exports.cmake_output_directory = cmake_output_directory;
function cmake_exe_linker_flags() {
    return `set(CMAKE_EXE_LINKER_FLAGS "\${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")`;
}
exports.cmake_exe_linker_flags = cmake_exe_linker_flags;
function set_variable_multi_paths(var_name, paths) {
    let lines = [`set(${var_name}`];
    for (let path of paths) {
        lines.push(path_to_string(path));
    }
    lines.push(`)`);
    return lines;
}
exports.set_variable_multi_paths = set_variable_multi_paths;
// set property
function startup_project(project_name) {
    return `set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${str(project_name)})`;
}
exports.startup_project = startup_project;
function debugger_working_directory(project_name, dir) {
    let proj = str(project_name);
    let dir_str = path_to_string(dir.toLocaleString());
    return `set_property(TARGET ${proj} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY \${CMAKE_SOURCE_DIR}/${dir_str}/\${CMAKE_CFG_INTDIR})`;
}
exports.debugger_working_directory = debugger_working_directory;
function add_dependencies(depending, depended) {
    return `add_dependencies(${str(depending)} ${str(depended)})`;
}
exports.add_dependencies = add_dependencies;
