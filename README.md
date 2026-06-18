# DSLib: A High-Performance Generic Data Structures Library in Modern C++

> A competitive-programming-grade and systems-oriented implementation of classical data structures built from scratch using modern C++ and object-oriented design principles.

## Overview

DSLib is a reusable, extensible, and high-performance data structures library developed as part of the CS2710 course project at IIT Madras.

The goal of the project was to design a production-quality collection of fundamental data structures from first principles, focusing on:

* Generic programming using C++ templates
* Algorithmic efficiency
* Clean API design
* Extensibility through OOP principles
* Memory-efficient implementations
* Rigorous correctness testing

Unlike textbook implementations, this project emphasizes modularity, reusable abstractions, and competitive-programming-grade performance characteristics.

---

## Motivation

Most introductory implementations of data structures are tightly coupled to specific data types and are difficult to reuse across projects.

This project explores how core data structures can be designed as generic, reusable software components while preserving their theoretical complexity guarantees.

The resulting library can serve as:

* A learning resource for data structure internals
* A competitive programming toolkit
* A foundation for larger systems projects
* A reference implementation for common data structures

---

# Features

## Balanced Search Trees

### AVL Tree

Self-balancing binary search tree maintaining strict height balance.

Supported Operations:

```cpp
insert(key)
remove(key)
find(key)
lower_bound(key)
upper_bound(key)
```

Complexities:

| Operation | Complexity |
| --------- | ---------- |
| Search    | O(log n)   |
| Insert    | O(log n)   |
| Delete    | O(log n)   |

---

### Red-Black Tree

Self-balancing BST based on color invariants.

Features:

* Rotations
* Recoloring
* Height guarantees
* Ordered traversal

Complexities:

| Operation | Complexity |
| --------- | ---------- |
| Search    | O(log n)   |
| Insert    | O(log n)   |
| Delete    | O(log n)   |

---

### B-Tree

Multi-way balanced search tree optimized for block-based storage.

Features:

* Node splitting
* Node merging
* Arbitrary order support

Applications:

* Databases
* Filesystems
* External-memory algorithms

---

## Range Query Data Structures

### Segment Tree

Efficient range query and update processing.

Supported Queries:

```cpp
rangeSum(l, r)
rangeMin(l, r)
rangeMax(l, r)
pointUpdate(idx, value)
```

Complexities:

| Operation | Complexity |
| --------- | ---------- |
| Query     | O(log n)   |
| Update    | O(log n)   |
| Build     | O(n)       |

---

## String Processing

### Trie

Prefix tree implementation for efficient string retrieval.

Supported Operations:

```cpp
insert(word)
contains(word)
startsWith(prefix)
erase(word)
```

Applications:

* Dictionaries
* Auto-completion
* Search engines

---

## Priority Structures

### Binary Heap

Supported Variants:

* Min Heap
* Max Heap

Operations:

```cpp
push(x)
pop()
top()
```

Complexities:

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(log n)   |
| Delete    | O(log n)   |
| Peek      | O(1)       |

---

## Hash-Based Structures

### Hash Table

Custom hash-table implementation featuring:

* Collision handling
* Dynamic resizing
* Generic key-value storage

Operations:

```cpp
put(key, value)
get(key)
erase(key)
contains(key)
```

Expected Complexity:

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(1)       |
| Lookup    | O(1)       |
| Delete    | O(1)       |

---

# Architecture

The library follows a modular design:

```text
DSLib/
│
├── Trees/
│   ├── AVLTree.hpp
│   ├── RBTree.hpp
│   └── BTree.hpp
│
├── RangeStructures/
│   └── SegmentTree.hpp
│
├── Strings/
│   └── Trie.hpp
│
├── Priority/
│   └── Heap.hpp
│
├── Hashing/
│   └── HashTable.hpp
│
├── Tests/
│
└── Examples/
```

Each component is implemented independently with well-defined interfaces and reusable abstractions.

---

# Generic Programming

All major structures support template-based type parametrization.

Example:

```cpp
AVLTree<int> tree;
AVLTree<std::string> names;

HashTable<std::string, double> scores;
```

This allows the same implementation to operate on arbitrary user-defined types.

---

# Testing

Every data structure was validated through extensive testing covering:

* Correctness
* Boundary cases
* Degenerate inputs
* Randomized stress testing
* Complexity validation

Example test categories:

```text
✓ Empty structure operations
✓ Duplicate insertions
✓ Large random workloads
✓ Deletion edge cases
✓ Balancing invariants
✓ Range query correctness
```

---

# Performance Goals

The implementation preserves the best-known theoretical guarantees for all supported data structures.

| Data Structure | Search   | Insert   | Delete   |
| -------------- | -------- | -------- | -------- |
| AVL Tree       | O(log n) | O(log n) | O(log n) |
| Red-Black Tree | O(log n) | O(log n) | O(log n) |
| B-Tree         | O(log n) | O(log n) | O(log n) |
| Trie           | O(L)     | O(L)     | O(L)     |
| Heap           | O(1)*    | O(log n) | O(log n) |
| Hash Table     | O(1)*    | O(1)*    | O(1)*    |

* Expected complexity.

---

# Key Learnings

This project provided practical experience with:

* Object-Oriented Design
* Generic Programming
* Memory Management
* Algorithm Engineering
* Data Structure Invariants
* Template Metaprogramming
* Software Testing
* Performance Analysis

---

# Future Improvements

* Lazy Propagation Segment Trees
* Fenwick Trees
* Persistent Data Structures
* Treaps
* Splay Trees
* Graph Library
* Custom Memory Allocators
* Benchmarking Framework

---

## Author

**Deepanjan Das**

Indian Institute of Technology Madras

CS2710 Course Project
