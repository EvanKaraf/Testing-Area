#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "myforum.h"
#include "Header.h"

using namespace std;
int main() {
	srand(time(nullptr));
	forum newForum("Object Oriented Programming");
	//newForum.print();
	//newForum.createThread("Rules and other settings!");
	//newForum.printThread("Rules and other settings!");
	for (int i=0;i<3;i++) {
		newForum.createThread();
	}
	//
	//newForum.printThread("Rules and other settings!");

	//cout << "Creating random posts.." << endl;
	//for (int i = 0; i<2; i++) {
	//	newForum.createPost();
	//}
	//cout << "Showing random threads..." << endl;
	//for (int i = 0; i<5; i++) {
	//	newForum.printThread(Titles[rand() % 5]);
	//}
	//cout << endl << "Showing random posts..." << endl;
	//for (int i = 0 ; i < 5 ; i++) {
	//	newForum.printPost(rand() % newForum.getFID());
	//}

	btree Tree;
	vector<post> forumPosts = newForum.getAllPosts();
	for (vector<post>::size_type i = 0 ; i<forumPosts.size();i++) {
		Tree.insert(forumPosts[i]);
	}
	cout << "Printint BST inorder..." << endl;
	Tree.printInOrder();

	string emptyInt;
	cin >> emptyInt;
	return 0;
}
