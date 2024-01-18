"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.SolutionConfig = exports.ProjectConfig = exports.QtProjectConfig = exports.CxxStandard = exports.cxx_20 = exports.cxx_17 = exports.cxx_14 = exports.cxx_11 = exports.ProjectType = exports.static_library = exports.dynamic_link_library = exports.desktop_application = exports.console_application = void 0;
exports.console_application = 'console-application';
exports.desktop_application = 'desktop-application';
exports.dynamic_link_library = 'dynamic-link-library';
exports.static_library = 'static-library';
var ProjectType;
(function (ProjectType) {
    ProjectType[ProjectType["CONSOLE_APPLICATION"] = 0] = "CONSOLE_APPLICATION";
    ProjectType[ProjectType["DESKTOP_APPLICATION"] = 1] = "DESKTOP_APPLICATION";
    ProjectType[ProjectType["DYNAMIC_LINK_LIBRARY"] = 2] = "DYNAMIC_LINK_LIBRARY";
    ProjectType[ProjectType["STATIC_LIBRARY"] = 3] = "STATIC_LIBRARY";
})(ProjectType || (exports.ProjectType = ProjectType = {}));
exports.cxx_11 = 11;
exports.cxx_14 = 14;
exports.cxx_17 = 17;
exports.cxx_20 = 20;
var CxxStandard;
(function (CxxStandard) {
    CxxStandard[CxxStandard["CXX_11"] = 0] = "CXX_11";
    CxxStandard[CxxStandard["CXX_14"] = 1] = "CXX_14";
    CxxStandard[CxxStandard["CXX_17"] = 2] = "CXX_17";
    CxxStandard[CxxStandard["CXX_20"] = 3] = "CXX_20";
})(CxxStandard || (exports.CxxStandard = CxxStandard = {}));
class QtProjectConfig {
    constructor() {
        this.auto_uic = true;
        this.auto_moc = true;
        this.auto_rcc = true;
        this.packages = [];
        this.console = false;
    }
}
exports.QtProjectConfig = QtProjectConfig;
class ProjectConfig {
    constructor() {
        this.name = '';
        this.project_path = '';
        this.type = ProjectType.CONSOLE_APPLICATION;
        this.target_filename = '';
        this.files = [];
        this.definitions = [];
        this.include_current_dir = true;
        this.cxx_standard = CxxStandard.CXX_11;
        this.cxx_standard_required = true;
        this.include_directories = [];
        this.link_directories = [];
        this.link_libraries = [];
        this.internal_includes = [];
        this.internal_libraries = [];
    }
}
exports.ProjectConfig = ProjectConfig;
class SolutionConfig {
    constructor() {
        this.name = '';
        this.solution_path = '';
        this.version = '0.1';
        this.output_directory = '';
        this.subdirectories = [];
        this.startup_project = '';
        this.debugger_working_directory = '';
    }
}
exports.SolutionConfig = SolutionConfig;
