cmake_minimum_required(VERSION 3.16.3)

project(CxxTutorial VERSION 1.0.0 LANGUAGES C CXX)

set(EXECUTABLE_NAME Executable)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

include(AddGitSubmodule)

add_git_submodule(external/json)
add_git_submodule(external/catch2)
add_git_submodule(external/cxxopts)
add_git_submodule(external/fmt)
add_git_submodule(external/spdlog)

add_subdirectory(configured)
add_subdirectory(external)
add_subdirectory(app)