#define CATCH_CONFIG_MAIN
#include "../external/catch.hpp"
#include "../src/linkedList.hpp"

class LinkedListValueFixture {
 public:
  std::vector<char> values;
  LinkedListValueFixture() {
    for (char i = 'A'; i <= 'Z'; ++i) {
      values.push_back(i);
    }
  }
};

TEST_CASE_METHOD(LinkedListValueFixture,
                 "LinkedList insert, find, getFound and clear") {
  LinkedList<char> list;
  for (int i = values.size() - 1; i >= 0; --i) {
    list.insertFront(values[i]);
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
