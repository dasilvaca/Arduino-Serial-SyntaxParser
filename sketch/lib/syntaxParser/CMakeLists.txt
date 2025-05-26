cmake_minimum_required(VERSION 3.14)
project(NodeTest)

set(CMAKE_CXX_STANDARD 17)
include_directories(src)
include_directories(external)

add_executable(test_node.out tests/testNode.cpp)
add_executable(test_linkedlist.out tests/testLinkedList.cpp)
add_executable(test_trie.out tests/testTrie.cpp)
