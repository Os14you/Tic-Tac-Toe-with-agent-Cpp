# Specify the minimum version of CMake required to build this project.
cmake_minimum_required(VERSION 3.10)

# Define the project name. This will be the name of the solution in IDEs.
project(TicTacToe)

# --- Configuration ---

# Set the C++ standard to C++17. This is important for using features
# like std::filesystem.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- File Discovery ---

# Automatically find all .cpp files in the 'src' directory and store them
# in the SOURCES variable. This way, you don't have to list every new file manually.
file(GLOB_RECURSE SOURCES "src/*.cpp")

# --- Target Definition ---

# Define the executable target. We'll name it 'tictactoe'.
# It will be built from the files listed in the SOURCES variable.
add_executable(tictactoe ${SOURCES})

# --- Include Directories ---

# Tell the compiler to look for header files in the 'include' directory.
# This is equivalent to the -Iinclude flag in g++.
target_include_directories(tictactoe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Output Directory ---

# Set the property for the executable file to be placed in the 'build' directory
# after compilation, keeping the root directory clean.
set_target_properties(tictactoe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# A message to show when CMake configures the project successfully.
message(STATUS "Project configured. Build files are in the 'build' directory.")