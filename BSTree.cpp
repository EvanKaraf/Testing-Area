#include <iostream>
using namespace std;
#include "Header.h"


void btree::insert(ItemType item) {
	root = insert(root, item);
}

void btree::destroy() {
	if (!root) {
		cout << "Attemp to destroy an empty tree!" << endl;
		return;
	}
	destroy(root);
}

TreeNode* btree::search(ItemType itemToSearch) {
	if (!root) {
		cout << "Attemp to destroy an empty tree!" << endl;
		return nullptr;
	}
	cout << "Searching for post..."  <<  endl;
	TreeNode* searchNode;
	searchNode =  search(root, itemToSearch);
	if (searchNode == nullptr)
		cout << "Couldnt find the item!" << endl;
	else
		cout << "Success" << endl;
	return searchNode;
}

void btree::printInOrder() {
	printInOrder(root);
}

void btree::printInOrder(TreeNode* root) {
	if (root) {
		printInOrder(root->left);
		for (list<post>::iterator it = root->creatorsPost.begin(); it != root->creatorsPost.end(); it++) {
			it->printPost();
			cout << endl;
		}
		printInOrder(root->right);
	}
}

TreeNode* btree::insert(TreeNode* root,ItemType itemToPlace) {
	if (root == nullptr || root->creator == itemToPlace.getPoster()) {
		root->creatorsPost.push_back(itemToPlace);
		root->creator = itemToPlace.getPoster();
		root->right = nullptr;
		root->left = nullptr;
	}
	else {
		if (itemToPlace.getPoster() > root->creator)
			root->right = insert(root->right, itemToPlace);
		else if (itemToPlace.getPoster() < root->creator)
			root->left = insert(root->left, itemToPlace);
	}
	return root;
}

void btree::destroy(TreeNode* root) {
	if (root->right)
		destroy(root->right);
	if (root->left)
		destroy(root->left);
	delete root;
}

TreeNode* btree::search(TreeNode* root,ItemType itemToFind) {
	if (root) {
		if (root->creator == itemToFind.getPoster()) {
			return root;
		}
		else if (itemToFind.getPoster() > root->creator)
			return search(root->right, itemToFind);
		else
			return search(root->left, itemToFind);
	}
	else
		return nullptr;
}

btree::btree() {
	root = nullptr;
}
