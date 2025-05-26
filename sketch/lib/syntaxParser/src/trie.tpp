#pragma once

#include "trie.hpp"

template <typename ValueType>
Trie<ValueType>::Trie(char key) : key(key), value(), isTerminal(false) {}

template <typename ValueType>
Trie<ValueType>::~Trie() {
  clear();
}

template <typename ValueType>
char Trie<ValueType>::getKey() const {
  return this->key;
}

template <typename ValueType>
ValueType* Trie<ValueType>::getValue() {
  return &value;
}

template <typename ValueType>
void Trie<ValueType>::setValue(const ValueType& value) {
  this->value = value;
}

template <typename ValueType>
bool Trie<ValueType>::isKey() const {
  return this->isTerminal;
}

template <typename ValueType>
void Trie<ValueType>::markAsTerminal(bool state /* = true */) {
  this->isTerminal = state;
}

/* Comparison operator to find matching nodes into children */
template <typename ValueType>
bool Trie<ValueType>::operator==(const Trie<ValueType>& other) const {
  return this->key == other.key;
}

template <typename ValueType>
Trie<ValueType>* Trie<ValueType>::getChild(char key) const {
  Trie<ValueType> *search = new Trie<ValueType>(key);
  Trie<ValueType>* found = nullptr;
  children.getFound(search, found);
  delete search;
  return found;
}

template <typename ValueType>
Trie<ValueType>* Trie<ValueType>::addChild(char key) {
  Trie<ValueType>* found = getChild(key);
  if (found) return found;

  Trie<ValueType>* newNode = new Trie<ValueType>(key);
  children.insertFront(newNode);
  return newNode;
}

template <typename ValueType>
void Trie<ValueType>::insert(const char* word, const ValueType& val) {
    Trie<ValueType>* current = this;
    
    for (unsigned int i = 0; word[i]; ++i) {
        char ch = word[i];
        Trie<ValueType>* child = current->addChild(ch);
        current = child;
    }
    
    current->markAsTerminal(true);
    if (current->getValue() == nullptr) {
        current->setValue(val);
    }
}

template <typename ValueType>
Trie<ValueType>* Trie<ValueType>::find(const char* word) {
  Trie<ValueType>* current = this;

  for (unsigned int i = 0; word[i]; ++i) {
    char ch = word[i];
    Trie<ValueType>* child = current->getChild(ch);
    if (!child) return nullptr;
    current = child;
  }

  return current->isKey() ? current : nullptr;
}


template <typename ValueType>
void Trie<ValueType>::clear() {
  Node<Trie<ValueType>*>* node = children.getHead();
  while (node) {
    Node<Trie<ValueType>*>* next = node->getNext();
    delete node->getValue();
    node = next;
  }
  children.clear();
}
