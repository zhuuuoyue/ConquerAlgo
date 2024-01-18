"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.search_solution_and_projects = void 0;
const fs_1 = require("fs");
const path_1 = require("path");
const constants_1 = require("./constants");
function cmake_config_path(dir) {
    return (0, path_1.join)(dir.toLocaleString(), constants_1.cmake_config_filename);
}
function search_projects(solution_dir) {
    let solution_cmake_config_path = cmake_config_path(solution_dir);
    let projects = [];
    let directories = [solution_dir];
    while (directories.length != 0) {
        let current_directory = directories.pop();
        if (current_directory === undefined) {
            continue;
        }
        let children = (0, fs_1.readdirSync)(current_directory);
        for (let child of children) {
            if (child == '.' || child == '..') {
                continue;
            }
            let child_path = (0, path_1.join)(current_directory.toLocaleString(), child);
            if (solution_cmake_config_path === child_path) {
                continue; // ignore solution
            }
            let child_state = (0, fs_1.statSync)(child_path);
            if (child_state.isFile() && child === constants_1.cmake_config_filename) {
                projects.push(child_path);
                break;
            }
            if (child_state.isDirectory()) {
                directories.push(child_path);
            }
        }
    }
    return projects;
}
function search_solution_and_projects(source_dir) {
    let source_dir_state = (0, fs_1.statSync)(source_dir);
    if (!source_dir_state.isDirectory()) {
        return;
    }
    let children = (0, fs_1.readdirSync)(source_dir);
    if (children.indexOf(constants_1.cmake_config_filename) == -1) {
        return;
    }
    let solution_cmake = cmake_config_path(source_dir);
    let project_cmake_paths = search_projects(source_dir);
    return {
        solution_cmake_path: solution_cmake,
        project_cmake_paths: project_cmake_paths,
    };
}
exports.search_solution_and_projects = search_solution_and_projects;
