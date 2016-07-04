#ifndef BINARY_TREE_HEADER
#define BINARY_TREE_HEADER
#include "myforum.h"
#include <list>

typedef post ItemType;

class TreeNode {
public:
	std::string creator;
	std::list<post> creatorsPost;
	TreeNode* right;
	TreeNode* left;
};

class btree {
public:
	void insert(ItemType);
	void destroy();
	TreeNode* search(ItemType);
	void printInOrder();
	btree();

private:
	TreeNode* insert(TreeNode*, ItemType);
	void destroy(TreeNode*);
	TreeNode* search(TreeNode*, ItemType);
	void printInOrder(TreeNode*);
	TreeNode* root;
};
#endif // !BINARY_TREE_HEADER
