#pragma once

template <typename ValueType>
LinkedList<ValueType>::LinkedList() : head(nullptr) {}

template <typename ValueType>
LinkedList<ValueType>::~LinkedList() {
  clear();
}

template <typename ValueType>
void LinkedList<ValueType>::insertFront(const ValueType& value) {
  auto* newNode = new Node<ValueType>(value);
  newNode->setNext(this->head);
  this->head = newNode;
}

template <typename ValueType>
void LinkedList<ValueType>::setComparator(bool (*comparator)(const ValueType&, const ValueType&)) {
  this->comparator = comparator;
}

template <typename ValueType>
Node<ValueType>* LinkedList<ValueType>::find(const ValueType& value) const {
  Node<ValueType>* current = this->head;
  while (current) {
    if (this->comparator == nullptr) {
      if (current->getValue() == value) {
        return current;
      }
    } else {
      if (this->comparator(current->getValue(), value)) {
        return current;
      }
    }
    current = current->getNext();
  }
  return nullptr;
}

/**
 * @brief Searches for a node containing the specified value and retrieves its
 * value if found.
 *
 * This method searches the linked list for a node whose value matches the
 * provided `value`. If such a node is found, its value is assigned to the `out`
 * parameter and the method returns true. Otherwise, `out` remains unchanged and
 * the method returns false.
 *
 * @tparam ValueType The type of values stored in the linked list.
 * @param value The value to search for in the list.
 * @param[out] out Reference to a variable where the found value will be stored
 * if found.
 * @return true if a node with the specified value is found, false otherwise.
 */
template <typename ValueType>
bool LinkedList<ValueType>::getFound(const ValueType& value,
                                     ValueType& out) const {
  Node<ValueType>* node = find(value);
  if (node) {
    out = node->getValue();
    return true;
  }
  return false;
}

template <typename ValueType>
void LinkedList<ValueType>::clear() {
  auto* current = this->head;
  while (current) {
    auto* next = current->getNext();
    delete current;
    current = next;
  }
  this->head = nullptr;
}

template <typename ValueType>
Node<ValueType>* LinkedList<ValueType>::getHead() const {
  return this->head;
}

template <typename ValueType>
void LinkedList<ValueType>::deleteValue(const ValueType& value) {
  Node<ValueType>* current = this->head;
  Node<ValueType>* previous = nullptr;

  while (current) {
    if (current->getValue() == value) {
      if (previous) {
        previous->setNext(current->getNext());
      } else {
        this->head = current->getNext();
      }
      delete current;
      return;
    }
    previous = current;
    current = current->getNext();
  }
}

template <typename ValueType>
bool LinkedList<ValueType>::isEmpty() const {
  return this->head == nullptr;
}