#include <bits/stdc++.h>
#include "binaryTree.h"
// #include "bst.h"
using namespace std;

int main()
{
	BinarySearchTree bt1;
	bt1.insert(35);
	// bt1.insert(30);
	// bt1.insert(33);
	// // bt1.insert(32);
	// bt1.insert(40);
	// bt1.insert(36);
	// bt1.insert(45);
	// bt1.insert(43);
	// bt1.preOrderTraversal();
	
	// cout << "\n";
	// cout << "Search: " << bt1.search(90) << "\n";
	int value =-1;
	while (value)
	{
		cout << "Enter Value: ";cin >> value;
		bt1.remove(value);
	}
	// bt1.remove(5);
	// cout << "Ht of tree: " << bt1.height(bt1.getRoot()) << endl;
	// bt1.print_nodes_highest_height(bt1.getRoot());
	// BinaryTree bt2;
	// bt2.setRoot(mirrorBinaryTree(bt1.getRoot()));
	// bt2.preOrderTraversal();
	// cout << compareBinaryTree(bt1.getRoot(), bt1.cloneBinaryTree(bt1.getRoot()) )<< endl;	

	// BinaryTree bt2;
	// bt2.setRoot(bt1.cloneBinaryTree(bt1.getRoot()));
	// bt1.postOrderTraversal(bt1.getRoot());
	// cout << endl;
	// bt2.postOrderTraversal(bt2.getRoot());

	return 0;
}
