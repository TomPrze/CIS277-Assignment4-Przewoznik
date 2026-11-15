# CIS-277 Assignment 4: Binary Tree Explorer
## Student
Tomasz Przewoznik
## Design
This program will construct trees, return their traversal sequences, measure their structure, and release their memory safely. Each node stores an integer and up to two child pointers. An empty tree returns a count of zero nodes. Traversals collect visited values in a vector. The programmer is responsible for releasing allocated nodes.
## How to Compile
The programs are compiled using a C++23 compiler with warning flags enabled.

To compile the main demonstration program, run:

```sh
g++ -std=c++23 -Wall -Wextra -pedantic main.cpp TreeExplorer.cpp -o tree_explorer
```

To compile the student test program, run:

```sh
g++ -std=c++23 -Wall -Wextra -pedantic -I. tests/student_tests.cpp TreeExplorer.cpp -o student_tests
```
## How to Run
To run the main demonstration program, use:

```sh
./tree_explorer
```

To run the student tests, use:

```sh
./student_tests
```

To run the assignment validator, use:

```sh
python validate.py
```

## Tests and Results
The student tests use assert to check that each function produces the expected result.

The following test cases were included:

Empty tree: Checks that traversals return empty vectors and measurements return zero.

Single-node tree: Checks traversals and measurements for a tree containing one node with a value of -4.

Left-only tree: Checks traversal order, node count, leaf count, height, and sum for a tree with four nodes connected to the left.

Right-only tree: Checks traversal order, node count, leaf count, height, and sum for a tree with four nodes connected to the right.

Duplicate and negative values: Checks that traversals and measurements work correctly with duplicate values, zero, and negative numbers.

Repeated traversals: Checks that calling a traversal multiple times returns consistent results and that changing the returned vector does not change the original tree.

Destroying and rebuilding a tree: Checks that the tree is properly destroyed and that a new tree can be created afterward.

Unbalanced tree: Checks traversal order and measurements for a tree with branches of different heights.

The tests also check that destroyTree sets the root pointer to nullptr after deleting the tree.

Results: All eight test cases successfully passed.
## Analysis Questions
1. 
Pre: 30, 20, 40
In: 20, 30, 40
Post: 20, 40, 30
The sequence changes because each traversal method goes through the tree in a different order. The sum doesn't change because changing the order of numbers in addition doesn't change the result (Commutative Property).

2. 
Tree B is a binary tree because each node has at most 2 children. It is not a BST because the left child of 10 is 30, which is greater than 10. In a BST, a node's left child has to be less than its parent. The inorder sequence isn't sorted because the tree doesn't follow BST.

3. 
Node 40's depth is 3. Depth in edge counts the lines connecting the top-most node to the bottom-most, while this assignment's height in levels counts the number of nodes you have to pass through to get from the top to the bottom.

4. 
The root is added first then removed and visited. Its children are added to the queue followed by their children. Since the first node added is the first node removed, the tree is visited one level at a time, from left to right.

5. 
All traversals and measurements take O(n) time because they visit each node once. Depth-first traversal uses O(h) auxiliary space for its recursive call stack, while level-order traversal uses O(w) auxiliary space for its queue. The returned traversal vector separately requires O(n) space. Measurements use O(h) recursive stack space and do not require a returned vector. Destruction takes O(n) time and O(h) recursive stack space. A balanced tree has a height of approximately O(log n), while a chain can have a height of O(n). A normal traversal does not need dynamic-programming tabulation because each node is visited once.
6. 
Deletion uses postorder so that the children are deleted before the parent. TreeNode*& passes the parent root caller by reference, so it can be set to nullptr after deletion. If the parent was deleted before its children, the child nodes would leak and become inaccessible.

## AI Use
ChatGPT was used to help create the test code and for error fixing. While writing main.cpp I was encountering issues getting it to compile and run. After being unable to find any answers on the internet, I managed to get it running after finding out from ChatGPT that the issue was with Dev-C++, the IDE I use, rather than the code. It then assisted me in fixing the problem itself. It was also used to assist with question 5.
