#pragma once

#include "linkedList.hpp"
#include "node.hpp"

template <typename ValueType>
class Trie {
 private:
  char key;
  ValueType value;
  bool isTerminal;
  LinkedList<Trie<ValueType>*> children;
  void setValue(const ValueType& value);

 public:
  Trie(char key = '\0');
  ~Trie();

  void insert(const char* word, const ValueType& value);
  Trie<ValueType>* find(const char* word);

  char getKey() const;
  ValueType* getValue();
  bool isKey() const;
  void markAsTerminal(bool state = true);

  bool operator==(const Trie<ValueType>& other) const;

  void clear();
  Trie<ValueType>* getChild(char key) const;
  Trie<ValueType>* addChild(char key);
};

#include "trie.tpp"
