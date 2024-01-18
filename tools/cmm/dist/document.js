"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Document = void 0;
const fs_1 = require("fs");
const path_1 = require("path");
const lodash_1 = __importDefault(require("lodash"));
const constants_1 = require("./constants");
class Document {
    constructor() {
        this.lines = [];
    }
    add(line_or_lines) {
        if (lodash_1.default.isString(line_or_lines)) {
            this.lines.push(line_or_lines);
        }
        else if (lodash_1.default.isArray(line_or_lines)) {
            for (let line of line_or_lines) {
                if (lodash_1.default.isString(line)) {
                    this.lines.push(line);
                }
            }
        }
    }
    save(project_directory) {
        let filename = (0, path_1.join)(project_directory.toLocaleString(), constants_1.cmake_lists_filename);
        let text = this.lines.join('\n');
        (0, fs_1.writeFileSync)(filename.toLocaleString(), text, { flag: 'w' });
    }
}
exports.Document = Document;
