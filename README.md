# ACC COSC 2436 Labs

This repository contains four separate labs for the ACC COSC 2436 course. Each lab explores a data structure in C++ and includes small sample programs demonstrating their use.

## Lab1 – ArrayBag

`lab1` implements a simple array‑based Bag class. `BagInterface.h` defines the required operations, `ArrayBag.h`/`ArrayBag.cpp` provide the implementation (including bubble sort and binary search methods), and `usingArrayBag.cpp` is a menu‑driven demonstration program. A tiny file named `d` is also present but unused.

Key excerpt from `usingArrayBag.cpp` describing the program:
```
/* Program Description:
 * Displays a menu to the user and prompts for a choice
 * The user can choose a choice from 1-7
 * These choices allow the user to display, store, remove, sort, and search
 * (using one of two algorithms) a containers contents.
 * Additionally, the user can exit the program.
 */
```

## Lab2 – LinkedStack

`lab2` introduces a linked‑list implementation of a stack. `StackInterface.h` defines the interface, `Node.h`/`Node.cpp` represent list nodes, and `LinkedStack.h`/`LinkedStack.cpp` implement the stack. `client.cpp` uses the stack to read `auctions.txt` and output the largest bid.

Snippet from `client.cpp`:
```
/* Program Description: Opens a file containing bids, finds the largest one,
 * and outputs it to the user.
 */
```

## Lab3 – LinkedList

`lab3` builds a singly linked list storing lines of text in sorted order. `LinkedList.h`/`LinkedList.cpp` manage the list and `Node.h`/`Node.cpp` define each node. `client.cpp` loads lines from a file and reports the results. Example text files (`alpha1.txt`, `alpha2.txt`, etc.) are provided along with a `template version` folder containing a templated variant of the same code.

Example constructor comment from `LinkedList.cpp`:
```
//A constructor given no arguments will implicitly assign headPtr to nullptr and lineCount to 0
```

## Lab4 – EmployeeTree

`lab4` implements a binary search tree to manage employee records. `EmployeeInfo.h`/`EmployeeInfo.cpp` describe individual nodes and `EmployeeTree.h`/`EmployeeTree.cpp` provide tree operations such as insertion, deletion, and traversal. `client.cpp` offers an interactive menu (requires Windows console support) while `clientNoMenu.cpp` is a simpler text version. `employeeData.txt` holds sample employee information:
```
6702 James B W Bevis
1255 Romney Wordsworth
...
```

Beginning of `client.cpp`:
```
/* Program Description:
 * Opens a file containing employee data and stores it inside a binary
 * search tree. The user can select options from a menu to perform operations
 * on the data.
 */
```

---
Each lab is standalone and demonstrates usage of the respective data structure. Compile the `.cpp` files in each directory to experiment with the provided examples.
