#define CATCH_CONFIG_MAIN
#include "../external/catch.hpp"
#include "../src/node.hpp"
#include "../src/node.tpp"


#include<vector>



std::vector<char> nodeValues;


TEST_CASE("Single node instantiation"){
    Node<char> testNode ('C');
    REQUIRE(testNode.getValue() == 'C');
}

