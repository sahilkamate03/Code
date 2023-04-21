#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
	string data;
	
	Node* left;
	Node* right;

	//if true thread exists
	bool flag_l; 
	bool flag_r;

	Node() : data{""}, left{nullptr}, right{nullptr}, flag_l{0}, flag_r{0} {}
	Node(string _data) : data{_data}, left{nullptr}, right{nullptr}, flag_l{0}, flag_r{0} {}
	Node(Node* _left, Node* _right) : data{""}, left{_left}, right{_right}, flag_l{0}, flag_r{0} {}
};

class ThreadedBinaryTree 
{
private:
	Node* root;
	Node* dummyNode;
	string inorderString;

public:
	// ThreadedBinaryTree(): {}
	ThreadedBinaryTree() : dummyNode{nullptr}, root{nullptr} {}
};

int main()
{

}
