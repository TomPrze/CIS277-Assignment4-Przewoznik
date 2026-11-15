#include "TreeExplorer.h"
#include <queue>
#include <algorithm>

namespace
{
	void preHelp(const TreeNode* root, std::vector<int>& result)
	{
	    if(root == nullptr)
	        return;
	
	    result.push_back(root->value);
	    preHelp(root->left, result);
	    preHelp(root->right, result);
	}
	
	void inHelp(const TreeNode* root, std::vector<int>& result)
	{
	    if(root == nullptr)
	        return;
	    
	    inHelp(root->left, result);
	    result.push_back(root->value);
	    inHelp(root->right, result);
	}
	
	void postHelp(const TreeNode* root, std::vector<int>& result)
	{
	    if(root == nullptr)
	        return;
	    
	    postHelp(root->left, result);
	    postHelp(root->right, result);
	    result.push_back(root->value);
	}
}

std::vector<int> preorder(const TreeNode* root)
{
	std::vector<int> result;
	preHelp(root, result);
	return result;
}

std::vector<int> inorder(const TreeNode* root)
{
	std::vector<int> result;
	inHelp(root, result);
	return result;
}

std::vector<int> postorder(const TreeNode* root)
{
	std::vector<int> result;
	postHelp(root, result);
	return result;
}

std::vector<int> levelOrder(const TreeNode* root)
{
	std::vector<int> result;
	
	if(root == nullptr)
		return result;
	
	std::queue<const TreeNode*> nodes;
	nodes.push(root);
		
	while(!nodes.empty())
	{
		const TreeNode* current = nodes.front();
		nodes.pop();
		result.push_back(current->value);
		
		if(current->left != nullptr)
	    nodes.push(current->left);
		if(current->right != nullptr)
    	nodes.push(current->right);
	}
	
	return result;
}

std::size_t countNodes(const TreeNode* root)
{
	if(root == nullptr)
		return 0;
	
	return 1 + countNodes(root->left) + countNodes(root->right);
}

std::size_t countLeaves(const TreeNode* root)
{
	if(root == nullptr)
		return 0;
	
	if(root->left == nullptr && root->right == nullptr)
		return 1;
	
	return countLeaves(root->left) + countLeaves(root->right);
}

int treeHeight(const TreeNode* root)
{
	if(root == nullptr)
		return 0;
	
	if(root->left == nullptr && root->right == nullptr)
		return 1;
	
	return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}

long long sumValues(const TreeNode* root)
{
	if(root == nullptr)
		return 0;
	
	if(root->left == nullptr && root->right == nullptr)
		return root->value;
	
	return root->value + sumValues(root->left) + sumValues(root->right);
}

void destroyTree(TreeNode*& root)
{
	if(root == nullptr)
		return;
	
	destroyTree(root->left);
	destroyTree(root->right);
	
	delete root;
	root = nullptr;
}