cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(KupynaHash VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(KupynaHash main.cpp kupyna_transform.cpp kalyna_transform.cpp kupyna_utils.cpp)

# Include directories
target_include_directories(KupynaHash PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           )
