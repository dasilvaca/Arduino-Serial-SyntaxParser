#pragma once

#include "linkedList.hpp"

template <typename ValueType>
class Trie {
 private:
  char key;
  ValueType value;
  bool isTerminal;

  LinkedList<Trie<ValueType>*> children;

  void initComparator(); 

 public:
  explicit Trie(char key = '\0');
  ~Trie();

  void insert(const char* word, const ValueType& value);
  Trie<ValueType>* find(const char* word);
  Trie<ValueType>* getChild(char key) const;
  Trie<ValueType>* addChild(char key);

  char getKey() const;
  ValueType* getValue();
  void setValue(const ValueType& value);
  bool isKey() const;
  void markAsTerminal(bool state = true);

  void clear();
};

#include "trie.tpp"