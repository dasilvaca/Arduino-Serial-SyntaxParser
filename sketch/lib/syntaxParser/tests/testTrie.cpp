#define CATCH_CONFIG_MAIN
#include "../src/trie.hpp"
#include "../external/catch.hpp"

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
