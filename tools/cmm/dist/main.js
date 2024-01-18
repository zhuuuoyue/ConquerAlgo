"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const process_1 = require("process");
const path_1 = require("path");
const fs_1 = require("fs");
const lodash_1 = __importDefault(require("lodash"));
const command_line_args_1 = __importDefault(require("command-line-args"));
const search_1 = require("./search");
const parse_1 = require("./parse");
const write_1 = require("./write");
const context_1 = require("./context");
function main(context) {
    if (lodash_1.default.isUndefined(context.solution_directory)) {
        return;
    }
    let solution = (0, search_1.search_solution_and_projects)(context.solution_directory);
    if (lodash_1.default.isUndefined(solution)) {
        return;
    }
    let configs = (0, parse_1.parse_solution_and_projects)(solution.solution_cmake_path, solution.project_cmake_paths);
    if (lodash_1.default.isUndefined(configs)) {
        return;
    }
    for (let project_name in configs.project_configs) {
        let project_config = configs.project_configs[project_name];
        let writer = new write_1.ProjectWriter(project_config);
        writer.write(context, configs.solution_config, configs.project_configs);
    }
    let writer = new write_1.SolutionWriter(configs.solution_config);
    writer.write(context, configs.solution_config, configs.project_configs);
}
const SOLUTION_DIR = 'solution_dir';
const CMAKE_MINIMUM_REQUIRED = 'cmake_minimum_required';
let context = new context_1.Context();
let current_working_directory = (0, process_1.cwd)();
let children = (0, fs_1.readdirSync)(current_working_directory);
let debug_config_filename = 'debug.json';
if (children.indexOf(debug_config_filename) != -1) {
    let debug_config_file_state = (0, fs_1.statSync)((0, path_1.join)(current_working_directory, debug_config_filename));
    if (debug_config_file_state.isFile()) {
        let data = (0, fs_1.readFileSync)(debug_config_filename).toLocaleString();
        let obj = JSON.parse(data);
        if (lodash_1.default.has(obj, CMAKE_MINIMUM_REQUIRED) && lodash_1.default.isString(obj[CMAKE_MINIMUM_REQUIRED])) {
            context.cmake_minimum_required = obj[CMAKE_MINIMUM_REQUIRED];
        }
        if (lodash_1.default.has(obj, SOLUTION_DIR) && lodash_1.default.isString(obj[SOLUTION_DIR])) {
            context.solution_directory = obj[SOLUTION_DIR];
        }
    }
}
else {
    const argument_definitions = [
        { name: SOLUTION_DIR, type: String },
        { name: CMAKE_MINIMUM_REQUIRED, type: String, defaultValue: '3.5' },
    ];
    const argument_options = {
        argv: process.argv,
    };
    const args = (0, command_line_args_1.default)(argument_definitions, argument_options);
    if (lodash_1.default.has(args, SOLUTION_DIR) && lodash_1.default.isString(args[SOLUTION_DIR])) {
        let solution_dir = args[SOLUTION_DIR];
        if (!(0, path_1.isAbsolute)(solution_dir)) {
            let workspace = (0, process_1.cwd)();
            solution_dir = (0, path_1.join)(workspace, solution_dir);
        }
        context.solution_directory = solution_dir;
    }
    else {
        console.log('Argument Error: parameter solution_dir was not set.');
    }
    if (lodash_1.default.has(args, CMAKE_MINIMUM_REQUIRED)) {
        context.cmake_minimum_required = args[CMAKE_MINIMUM_REQUIRED];
    }
}
main(context);
