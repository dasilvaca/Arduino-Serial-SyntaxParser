#define CATCH_CONFIG_MAIN
#include "../src/trie.hpp"
#include "../external/catch.hpp"

TEST_CASE("Trie addChild and getChild") {
  Trie<int> trie;
  Trie<int>* childA = trie.addChild('a');
  childA->setValue(1);
  
  Trie<int>* childB = trie.addChild('b');
  childB->setValue(2);

  Trie<int>* foundA = trie.getChild('a');
  REQUIRE(foundA != nullptr);
  REQUIRE(*foundA->getValue() == 1);

  Trie<int>* foundB = trie.getChild('b');
  REQUIRE(foundB != nullptr);
  REQUIRE(*foundB->getValue() == 2);

  Trie<int>* notFound = trie.getChild('c');
  REQUIRE(notFound == nullptr);
}

TEST_CASE("Trie insert and find") {
  Trie<std::string> trie;
  trie.insert("hello", "world");
  trie.insert("hi", "there");

  Trie<std::string>* found = trie.find("hello");
  REQUIRE(found != nullptr);
  REQUIRE(*found->getValue() == "world");

  found = trie.find("hi");
  REQUIRE(found != nullptr);
  REQUIRE(*found->getValue() == "there");

  found = trie.find("unknown");
  REQUIRE(found == nullptr);
}


