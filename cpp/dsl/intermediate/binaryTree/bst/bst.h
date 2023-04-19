#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

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

    friend class BinarySearchTree;
};

class BinarySearchTree
{
private:
    Node* root;

public:
    BinarySearchTree(): root{nullptr} {}

    Node* getRoot() const {return root;}
    void setRoot(Node* newRoot) {root=newRoot;}  

    void insert(int);
    bool search(int);

    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
};

#endif
