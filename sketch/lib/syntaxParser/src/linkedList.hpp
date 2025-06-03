#pragma once

#include "node.hpp"

template <typename ValueType>
class LinkedList {
  bool (*comparator)(const ValueType&, const ValueType&) = [](const ValueType& a, const ValueType& b) {
    return a == b;
  };

 private:
  Node<ValueType>* head;

 public:
  LinkedList();
  ~LinkedList();

  void insertFront(const ValueType& value);
  Node<ValueType>* find(const ValueType& value) const;
  bool getFound(const ValueType& value, ValueType& out) const;

  void deleteValue(const ValueType& value);
  void setComparator(bool (*comparator)(const ValueType&, const ValueType&));

  void clear();
  Node<ValueType>* getHead() const;
  bool isEmpty() const;
};

#include "linkedList.tpp"
