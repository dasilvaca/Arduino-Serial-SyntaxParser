cmake_minimum_required(VERSION 3.14)
project(NodeTest)

set(CMAKE_CXX_STANDARD 17)
include_directories(src)
include_directories(external)

add_executable(test_node tests/testNode.cpp)
add_executable(test_linkedlist tests/testLinkedList.cpp)
add_executable(test_trie tests/testTrie.cpp)
