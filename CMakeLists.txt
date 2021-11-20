cmake_minimum_required(VERSION 3.0.0)
project(Practice VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
add_subdirectory(1_Trie_structure)
add_subdirectory(2_matrix_class)

