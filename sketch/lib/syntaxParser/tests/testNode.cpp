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
            std::cout << "Node value added: " << i << std::endl;
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
        std::cout << "Current node value: " << itNode->getValue() << std::endl;
        Node<char> nextNode(value);
        itNode->setNext(&nextNode);
        itNode = itNode->getNext();
    }
    itNode = &testNode;
    char value = 'A';
    while(itNode->getNext() != nullptr) {
        std::cout << "Current node value: " << itNode->getValue() << std::endl;
        REQUIRE(itNode->getValue() == value);
        itNode = itNode->getNext();
        // value = ; // wrap around to 'A' after 'Z'
    }
}