#pragma once

#include <functional>  // for std::equal_to

#include "node.hpp"

namespace dataStructures {

template <typename ValueType>
class LinkedList {
  using Comparator = std::function<bool(const ValueType&, const ValueType&)>;

 private:
  Node<ValueType>* head;
  Comparator comparator;

 public:
  LinkedList();
  ~LinkedList();

  void insertFront(const ValueType& value);
  Node<ValueType>* find(const ValueType& value) const;
  bool getFound(const ValueType& value, ValueType& out) const;

  void deleteValue(const ValueType& value);
  void setComparator(Comparator comparator);

  void clear();
  Node<ValueType>* getHead() const;
  bool isEmpty() const;
};
}  // namespace dataStructures
#include "linkedList.tpp"
