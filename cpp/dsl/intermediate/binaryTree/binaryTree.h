#ifndef BINARYTREE_H
#define BINARYTREE_H

class Node
{
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(): data{0}, left{nullptr}, right{nullptr} {}
    Node(int data): data{data}, left{nullptr}, right{nullptr} {}

    int getData() const {return data;}
    Node* getLeft() const {return left;}
    Node* getRight() const {return right;}

    friend class BinaryTree;
    friend Node* cloneBinaryTree(Node*);
    friend Node* mirrorBinaryTree(Node* root);
};

class BinaryTree
{
private:
    Node* root;

public:
    BinaryTree(): root{nullptr} {}

    Node* getRoot() const {return root;}
    void setRoot(Node* newRoot) {root=newRoot;}  

    void insert(int);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();

};

bool compareBinaryTree(Node*, Node*);
Node* cloneBinaryTree(Node*);

#endif
