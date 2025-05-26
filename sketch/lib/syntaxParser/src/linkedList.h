#pragma once

#include "node.hpp"

template <typename ValueType>
class LinkedList {
 private:
  Node<ValueType>* head;

 public:
  LinkedList();
  ~LinkedList();

  void insertFront(const ValueType& value);
  Node<ValueType>* find(const ValueType& value) const;
  bool getFound(const ValueType& value, ValueType& out) const;

  void deleteValue(const ValueType& value);

  void clear();
  Node<ValueType>* getHead() const;
  bool isEmpty() const;
};

#include "linkedList.tpp"
