#include <iostream>
#include "TreeExplorer.h"
using namespace std;

int main()
{
	// Build Tree A
	TreeNode* rootA = new TreeNode{50};
	TreeNode* node30 = new TreeNode{30};
	TreeNode* node20 = new TreeNode{20};
	TreeNode* node40 = new TreeNode{40};
	TreeNode* node60 = new TreeNode{60};
    TreeNode* node70 = new TreeNode{70};
	TreeNode* node80 = new TreeNode{80};
	
	// Conncet Tree A
	rootA->left = node30;
    rootA->right = node70;
    rootA->left->left = node20;
    rootA->left->right = node40;
    rootA->right->left = node60;
    rootA->right->right = node80;
	
	// Tree A measurement
	cout << "Number of Nodes in A: " << countNodes(rootA) << endl;
	cout << "Number of Leaves in A: " << countLeaves(rootA) << endl;
	cout << "Tree A Height: " << treeHeight(rootA) << endl;
	cout << "Sum of Values in A: " << sumValues(rootA) << endl;
	
	cout << endl;
	
	// Tree A traversals
    vector<int> preA = preorder(rootA);
    cout << "Preorder: ";
    for (int value : preA)
        cout << value << " ";	
	cout << endl;
	
    vector<int> inA = inorder(rootA);
    cout << "Inorder: ";
    for (int value : inA)
        cout << value << " ";    
	cout << endl;
	
    vector<int> postA = postorder(rootA);
    cout << "Postorder: ";
    for (int value : postA)
        cout << value << " ";
	cout << endl;

    vector<int> levelA = levelOrder(rootA);
    cout << "Level order: ";
    for (int value : levelA)
        cout << value << " "; 
	cout << endl << endl;
	
    // Build Tree B
    TreeNode* rootB = new TreeNode{10};
    TreeNode* node30B = new TreeNode{30};
    TreeNode* node20B = new TreeNode{20};
    TreeNode* node5B = new TreeNode{5};
    TreeNode* node15B = new TreeNode{15};
	
    // Connect Tree B
    rootB->left = node30B;
    rootB->right = node20B;
    node30B->right = node5B;
    node20B->right = node15B;
	
	
    // Tree B measurements
	cout << "Number of Nodes in B: " << countNodes(rootB) << endl;
	cout << "Number of Leaves in B: " << countLeaves(rootB) << endl;
	cout << "Tree B Height: " << treeHeight(rootB) << endl;
	cout << "Sume of Values in B: " << sumValues(rootB) << endl;
	
	cout << endl;
	
    // Tree B traversals
    vector<int> preB = preorder(rootB);
    cout << "Preorder: ";
    for (int value : preB)
        cout << value << " ";
	cout << endl;
	
    vector<int> inB = inorder(rootB);
    cout << "Inorder: ";
    for (int value : inB)
        cout << value << " ";
    cout << endl;

    vector<int> postB = postorder(rootB);
    cout << "Postorder: ";
    for (int value : postB)
        cout << value << " ";
    cout << endl;
	
    vector<int> levelB = levelOrder(rootB);
    cout << "Level order: ";
    for (int value : levelB)
        cout << value << " ";
    cout << endl;
	
    destroyTree(rootA);
    destroyTree(rootB);
	
	cout << "Tree A remaining nodes: " << countNodes(rootA) << endl;
	cout << "Tree B remaining nodes: " << countNodes(rootB) << endl;
	
    return 0;

}
