#pragma once

template<typename ValueType>
Node<ValueType>::Node(const ValueType& value) {
  this->value = value;
  this->next = nullptr;
}

template<typename ValueType>
const ValueType& Node<ValueType>::getValue() const {
  return this->value;
}

template<typename ValueType>
void Node<ValueType>::setValue(const ValueType& value) {
  this->value = value;
}

template<typename ValueType>
Node<ValueType>* Node<ValueType>::getNext() const {
  return this->next;
}

template<typename ValueType>
void Node<ValueType>::setNext(Node<ValueType>* next) {
  this->next = next;
}
