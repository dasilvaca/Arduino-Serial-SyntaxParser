#pragma once

template<typename ValueType>
class Node {
 private:
  ValueType value;
  Node<ValueType>* next;

 public:
  explicit Node(const ValueType& value);
  const ValueType& getValue() const;
  void setValue(const ValueType& value);

  Node<ValueType>* getNext() const;
  void setNext(Node<ValueType>* next);
};

#include "node.tpp"
