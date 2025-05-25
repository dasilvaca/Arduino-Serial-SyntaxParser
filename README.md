# SyntaxParser

**SyntaxParser** is a modular and lightweight C++ library designed for use with Arduino (and other embedded systems) to build syntax-aware parsers and interpreters.

It provides:
- A templated `Node<T>` implementation
- Linked-list–based Trie structures (`ChildList`)
- Functional callbacks for syntax matching
- Unit-testable core components using Catch2 (desktop only)

---


---

## ✅ Features

- **Minimal templated linked list node**
- **Trie-based parsing**
- **Semantic actions via `std::function` callbacks**
- **PC-side unit testing with Catch2**
- **Designed for memory-constrained environments**

---

## 🚀 Quick Start (PC Testing with Catch2)

### 🔧 Requirements
- CMake ≥ 3.14
- g++ or clang++ with C++17 support

### 🛠️ Build and Run Tests

```bash
cd lib/syntaxParser
mkdir -p build && cd build
cmake ..
make
./test_node
