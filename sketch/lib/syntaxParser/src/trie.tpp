#pragma once

template <typename T>
Trie<T>::Trie(char key) : key(key), value(), isTerminal(false) {
  initComparator();
}

template <typename T>
Trie<T>::~Trie() {
  clear();
}

template <typename T>
void Trie<T>::initComparator() {
  children.setComparator([](const Trie<T>* a, const Trie<T>* b) {
    return a->getKey() < b->getKey();  // strict weak ordering for equality
  });
}

template <typename T>
char Trie<T>::getKey() const {
  return this->key;
}

template <typename T>
T* Trie<T>::getValue() {
  return &value;
}

template <typename T>
void Trie<T>::setValue(const T& value) {
  this->value = value;
}

template <typename T>
bool Trie<T>::isKey() const {
  return this->isTerminal;
}

template <typename T>
void Trie<T>::markAsTerminal(bool state) {
  this->isTerminal = state;
}

template <typename T>
Trie<T>* Trie<T>::getChild(char key) const {
  Trie<T> temp(key);
  Trie<T>* found = nullptr;
  children.getFound(&temp, found);
  return found;
}

template <typename T>
Trie<T>* Trie<T>::addChild(char key) {
  Trie<T>* existing = getChild(key);
  if (existing) return existing;

  Trie<T>* newNode = new Trie<T>(key);
  children.insertFront(newNode);
  return newNode;
}

template <typename T>
void Trie<T>::insert(const char* word, const T& val) {
  Trie<T>* current = this;

  for (unsigned int i = 0; word[i]; ++i) {
    current = current->addChild(word[i]);
  }

  current->markAsTerminal();
  current->setValue(val);
}

template <typename T>
Trie<T>* Trie<T>::find(const char* word) {
  Trie<T>* current = this;

  for (unsigned int i = 0; word[i]; ++i) {
    current = current->getChild(word[i]);
    if (!current) return nullptr;
  }

  return current->isKey() ? current : nullptr;
}

template <typename T>
void Trie<T>::clear() {
  Node<Trie<T>*>* node = children.getHead();
  while (node) {
    delete node->getValue();
    node = node->getNext();
  }
  children.clear();
}
