#define CATCH_CONFIG_MAIN
#include "../src/linkedList.hpp"

#include "../external/catch.hpp"

class LinkedListValueFixture {
public:
    LinkedListValueFixture() {
        for (char i = 'A'; i <= 'Z'; ++i) {
            values.push_back(i);
        }
    }

    std::vector<char> values;
};

TEST_CASE_METHOD(LinkedListValueFixture, "LinkedList insert, find, getFound and clear") {
    LinkedList<char> list;
    for (const char& value : values) {
        list.insertFront(value);
    }
    for (const char& value : values) {
        Node<char>* foundNode = list.find(value);
        REQUIRE(foundNode != nullptr);
        REQUIRE(foundNode->getValue() == value);
    }
    char foundValue;
    for (const char& value : values) {
        REQUIRE(list.getFound(value, foundValue));
        REQUIRE(foundValue == value);
    }
    REQUIRE(list.getFound('!', foundValue) == false);
    REQUIRE(foundValue != '!');
    REQUIRE(list.getHead() != nullptr);

    char deletedValue = values[0];
    list.deleteValue(deletedValue);
    REQUIRE(list.getFound(deletedValue, foundValue) == false);

    list.clear();
    REQUIRE(list.getHead() == nullptr);
    REQUIRE(list.isEmpty() == true);
}
