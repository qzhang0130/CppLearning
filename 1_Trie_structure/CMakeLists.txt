cmake_minimum_required(VERSION 3.1)
project(TrieStructure)
# version
set(Trie_VERSION_MAJOR 0)
set(Trie_VERSION_MINOR 0)
set(Trie_VERSION_PATCH 1)
set(Trie_VERSION "${Trie_VERSION_MAJOR}.${Trie_VERSION_MINOR}.${Trie_VERSION_PATCH}")
message(STATUS "The version of this project is: ${Trie_VERSION}")

# build type
set(CMAKE_BUILD_TYPE release)

add_subdirectory(${PROJECT_SOURCE_DIR}/test)

