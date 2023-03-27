#include <bits/stdc++.h>
#include "binaryTree.h"
using namespace std;

int main()
{
	BinaryTree bt1;
	bt1.insert(5);
	bt1.insert(8);
	bt1.insert(3);
	bt1.insert(1);
	bt1.insert(9);
	bt1.preOrderTraversal();
	
	cout << "Ht of tree: " << bt1.height(bt1.getRoot()) << endl;
	bt1.print_nodes_highest_height(bt1.getRoot());
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
