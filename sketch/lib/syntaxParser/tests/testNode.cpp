#define CATCH_CONFIG_MAIN
#include "../external/catch.hpp"
#include "../src/node.hpp"
#include "../src/node.tpp"


#include<vector>



std::vector<char> nodeValues;

struct NodeValuesFixture{
    std::vector<char> nodeValues;
    NodeValuesFixture(){
        for (char i = 'A'; i <= 'Z'; ++i) {
            nodeValues.push_back(i);
        }
    }
};


TEST_CASE_METHOD(NodeValuesFixture, "Single node instantiation"){
    for (const char& value : nodeValues) {
        Node<char> testNode(value);
        REQUIRE(testNode.getValue() == value);
    }
}

TEST_CASE_METHOD(NodeValuesFixture, "Single node value assignment"){
    Node<char> testNode('A');
    for (const char& value : nodeValues) {
        testNode.setValue(value);
        REQUIRE(testNode.getValue() == value);
    }
}

TEST_CASE_METHOD(NodeValuesFixture, "Single node next assignment"){
    Node<char> testNode('A');
    Node<char>* itNode = &testNode;
    for (const char& value : nodeValues) {
        Node<char> *nextNode = new Node<char>(value);
        itNode->setNext(nextNode);
        itNode = itNode->getNext();
    }
    itNode = &testNode;
    char value = 'A';
    bool firstPass = false;
    while(itNode != nullptr) {
        REQUIRE(itNode->getValue() == value);
        itNode = itNode->getNext();
        if (!firstPass) {
            firstPass = true;
        } else {
            value++;
        }
    }
}

TEST_CASE("Single node with pair as value") {
    Node<std::pair<int, int>> testNode(std::make_pair(1, 2));
    REQUIRE(testNode.getValue().first == 1);
    REQUIRE(testNode.getValue().second == 2);
}