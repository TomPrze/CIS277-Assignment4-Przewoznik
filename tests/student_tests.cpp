#include <iostream>
#include <vector>
#include <cassert>
#include "TreeExplorer.h"

using namespace std;

int main()
{
    cout << "Running student tests..." << endl;
	
	// Empty tree test
	TreeNode* emptyTree = nullptr;

    assert(preorder(emptyTree).empty());
    assert(inorder(emptyTree).empty());
    assert(postorder(emptyTree).empty());
    assert(levelOrder(emptyTree).empty());

    assert(countNodes(emptyTree) == 0);
    assert(countLeaves(emptyTree) == 0);
    assert(treeHeight(emptyTree) == 0);
    assert(sumValues(emptyTree) == 0);

    destroyTree(emptyTree);
    destroyTree(emptyTree);

    assert(emptyTree == nullptr);

    cout << "Empty tree test passed" << endl;
	
	// Singleton tree test
    TreeNode* singleTree = new TreeNode{-4};

    assert(preorder(singleTree) == vector<int>{-4});
    assert(inorder(singleTree) == vector<int>{-4});
    assert(postorder(singleTree) == vector<int>{-4});
    assert(levelOrder(singleTree) == vector<int>{-4});

    assert(countNodes(singleTree) == 1);
    assert(countLeaves(singleTree) == 1);
    assert(treeHeight(singleTree) == 1);
    assert(sumValues(singleTree) == -4);

    destroyTree(singleTree);

    assert(singleTree == nullptr);

    cout << "Singleton tree test passed!" << endl;
	
	// Left-only chain test
    TreeNode* leftTree = new TreeNode{1};
    leftTree->left = new TreeNode{2};
    leftTree->left->left = new TreeNode{3};
    leftTree->left->left->left = new TreeNode{4};

    assert(preorder(leftTree) == vector<int>({1, 2, 3, 4}));
    assert(inorder(leftTree) == vector<int>({4, 3, 2, 1}));
    assert(postorder(leftTree) == vector<int>({4, 3, 2, 1}));
    assert(levelOrder(leftTree) == vector<int>({1, 2, 3, 4}));

    assert(countNodes(leftTree) == 4);
    assert(countLeaves(leftTree) == 1);
    assert(treeHeight(leftTree) == 4);
    assert(sumValues(leftTree) == 10);

    destroyTree(leftTree);
    assert(leftTree == nullptr);

    cout << "Left-only chain test passed!" << endl;
	
	// Right-only chain test
    TreeNode* rightTree = new TreeNode{1};
    rightTree->right = new TreeNode{2};
    rightTree->right->right = new TreeNode{3};
    rightTree->right->right->right = new TreeNode{4};

    assert(preorder(rightTree) == vector<int>({1, 2, 3, 4}));
    assert(inorder(rightTree) == vector<int>({1, 2, 3, 4}));
    assert(postorder(rightTree) == vector<int>({4, 3, 2, 1}));
    assert(levelOrder(rightTree) == vector<int>({1, 2, 3, 4}));

    assert(countNodes(rightTree) == 4);
    assert(countLeaves(rightTree) == 1);
    assert(treeHeight(rightTree) == 4);
    assert(sumValues(rightTree) == 10);

    destroyTree(rightTree);
    assert(rightTree == nullptr);

    cout << "Right-only chain test passed!" << endl;
	
    // Duplicate, zero, and negative values test
    TreeNode* mixedTree = new TreeNode{0};

    mixedTree->left = new TreeNode{-5};
    mixedTree->right = new TreeNode{5};

    mixedTree->left->left = new TreeNode{-5};

    mixedTree->right->left = new TreeNode{0};
    mixedTree->right->right = new TreeNode{5};

    assert(preorder(mixedTree) == vector<int>({0, -5, -5, 5, 0, 5}));
	assert(inorder(mixedTree) == vector<int>({-5, -5, 0, 0, 5, 5}));
    assert(postorder(mixedTree) == vector<int>({-5, -5, 0, 5, 5, 0}));
    assert(levelOrder(mixedTree) == vector<int>({0, -5, 5, -5, 0, 5}));

    assert(countNodes(mixedTree) == 6);
    assert(countLeaves(mixedTree) == 3);
    assert(treeHeight(mixedTree) == 3);
    assert(sumValues(mixedTree) == 0);

    destroyTree(mixedTree);
    assert(mixedTree == nullptr);

    cout << "Mixed values test passed!" << endl;
	
	// Repeated traversal and modified vector test
    TreeNode* repeatTree = new TreeNode{10};
    repeatTree->left = new TreeNode{5};
    repeatTree->right = new TreeNode{15};

    vector<int> firstTraversal = preorder(repeatTree);
    vector<int> secondTraversal = preorder(repeatTree);

    assert(firstTraversal == vector<int>({10, 5, 15}));
    assert(secondTraversal == vector<int>({10, 5, 15}));

    // Modify the first returned vector
    firstTraversal[0] = 100;
    firstTraversal.push_back(20);

    // Check that the original tree is unchanged
    assert(preorder(repeatTree) == vector<int>({10, 5, 15}));

    destroyTree(repeatTree);
    assert(repeatTree == nullptr);

    cout << "Repeated traversal test passed!" << endl;
	
    // Destroy and rebuild test
    TreeNode* rebuildTree = new TreeNode{10};
    rebuildTree->left = new TreeNode{20};
    rebuildTree->right = new TreeNode{30};

    destroyTree(rebuildTree);

    assert(rebuildTree == nullptr);

    // Build a new tree using the same root pointer
    rebuildTree = new TreeNode{40};
    rebuildTree->left = new TreeNode{50};

    assert(countNodes(rebuildTree) == 2);
    assert(countLeaves(rebuildTree) == 1);
    assert(treeHeight(rebuildTree) == 2);
    assert(sumValues(rebuildTree) == 90);

    assert(preorder(rebuildTree) == vector<int>({40, 50}));

    destroyTree(rebuildTree);

    assert(rebuildTree == nullptr);

    cout << "Destroy and rebuild test passed!" << endl;
    
    // Additional unbalanced tree test
    TreeNode* extraTree = new TreeNode{8};

    extraTree->left = new TreeNode{4};
    extraTree->right = new TreeNode{12};
    extraTree->left->left = new TreeNode{2};
    extraTree->left->left->right = new TreeNode{3};

    assert(preorder(extraTree) == vector<int>({8, 4, 2, 3, 12}));
    assert(inorder(extraTree) == vector<int>({2, 3, 4, 8, 12}));
    assert(postorder(extraTree) == vector<int>({3, 2, 4, 12, 8}));
    assert(levelOrder(extraTree) == vector<int>({8, 4, 12, 2, 3}));

    assert(countNodes(extraTree) == 5);
    assert(countLeaves(extraTree) == 2);
    assert(treeHeight(extraTree) == 4);
    assert(sumValues(extraTree) == 29);

    destroyTree(extraTree);

    assert(extraTree == nullptr);

    cout << "Additional unbalanced tree test passed!" << endl;
	
    return 0;
}