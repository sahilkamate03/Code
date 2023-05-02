#include <bits/stdc++.h> 
 using namespace std; 

 class Node 
 { 
 private: 
         int data;
         Node* left; 
         Node* right; 

         //if true thread exists 
         bool flag_l;  
         bool flag_r; 

 public: 
     Node* getLeft() const {return left;} 
     Node* getRight() const {return right;} 
     int getData() const {return data;}
  
         Node() : data{-1}, left{nullptr}, right{nullptr}, flag_l{0}, flag_r{0} {} 
         Node(int _data) : data{_data}, left{nullptr}, right{nullptr}, flag_l{0}, flag_r{0} {} 
         Node(Node* dn, Node* root) : data{-1}, left{root}, flag_l{0}, flag_r{1} {right =dn;}
          
         friend class ThreadedBinaryTree; 
 }; 

 class ThreadedBinaryTree  
 { 
 private: 
         Node* root; 
         Node* dummyNode; 
         vector<Node*> inorderVector; 
 public: 

         // ThreadedBinaryTree(): {} 
         ThreadedBinaryTree()          
         { 
                 Node* rootNode =new Node;
                 Node* dm =new Node(dm, rootNode); 
                 
                 root =rootNode; 
                 dummyNode =dm;
         } 
        
         void inOrder();
         void inOrderMaker(Node*); 
         void insert(int); 
         void remove(int);
 }; 
 
 void ThreadedBinaryTree::inOrder()
 {
         
         if (root == nullptr) return;
         while (root->flag_l == 0)
            root = root->left;
            
         while (root != dummyNode)
         {
            cout << root->data << " ";
            
            if (root -> flag_r)
                root = root->right;
                
            else 
            {
                root = root->right;
                while (root->flag_l == 0) 
                    root = root->left;
            }
            
         }
 }

 void ThreadedBinaryTree::inOrderMaker(Node* currentNode) 
 { 
         if(currentNode == NULL) 
                 return; 

         inOrderMaker(currentNode->getLeft()); 
         inorderVector.push_back(currentNode); 
         inOrderMaker(currentNode->getRight()); 
 } 

 void ThreadedBinaryTree::insert(int value) 
 {       
         Node* parentNode =dummyNode;
         Node* currentNode =root; 
         
         if (currentNode->data == -1) 
         {                  currentNode->data =value; 
                 currentNode->left =parentNode;
                 currentNode->right =parentNode;
                 currentNode->flag_l =1;
                 currentNode->flag_r =1;
                 return;
         } 

         Node* newNode =new Node(value); 
 
         while (currentNode!=dummyNode) 
         { 
                 parentNode =currentNode;
                 if (currentNode->data > value) 
                 { 
                         if (currentNode->flag_l) 
                         { 
                                 newNode->left =currentNode->left;
                                 
                                 currentNode->left =newNode; 
                                 currentNode->flag_l =0;

                                 newNode->flag_l =1;                           
                                 newNode->right =currentNode;
                                 newNode->flag_r =1;
                                 return; 
                         } 
                         currentNode = currentNode->left; 
                 } 

                 else  
                 { 
                         if (currentNode->flag_r) 
                         { 
                                 newNode->right =currentNode->right;
                                 
                                 currentNode->right = newNode; 
                                 currentNode->flag_r =0;

                                 newNode->left =currentNode;
                                 newNode->flag_l =1;
                                 newNode->flag_r =1;
                                 return; 
                         } 

                         currentNode = currentNode->right; 
                 } 
         }         
 } 
 
 void ThreadedBinaryTree::remove(int value)
 {
    
 }

 

 void ThreadedBinaryTree::remove(int value) 
 { 
         Node* currentNode =this->root; 
         Node* parentNode =getParentNode(currentNode, value); 

         if (!parentNode) 
         { 
                 cout << "Not Present\n"; 
                 return; 
         } 
  
         currentNode =parentNode; 

         if (parentNode->left != NULL && parentNode->left->data == value) 
                 currentNode =parentNode->left; 

         else if (parentNode->right != NULL && currentNode->right->data == value) 
                 currentNode =parentNode->right; 

         // case 1: when both the left and right nodes are not present 
         if (!currentNode->left && !currentNode->right) 
         { 
                 if (parentNode->left == currentNode) 
                         parentNode->left =NULL; 

                 else  
                         parentNode->right =NULL; 

                 cout << currentNode->data << " is deleted\n"; 
                 delete currentNode; 
                 return; 
         } 

         // case 2: when left or right node is present  
         // part1 : when left node is present 
         if (currentNode->left!=NULL && currentNode->right==NULL) 
         { 
                 if (parentNode->left == currentNode) 
                         parentNode->left =currentNode->left; 
                 else  
                         parentNode->right =currentNode->left; 

                 cout << currentNode->data << "is deleted\n"; 
                 delete currentNode; 
                 return; 
         }
         
         // part2 : when right node is present 
         if (currentNode->left==NULL && currentNode->right!=NULL) 
         { 
                 if (parentNode->left == currentNode) 
                         parentNode->left =currentNode->right; 
                 else  
                         parentNode->right =currentNode->right; 
  
                 cout << currentNode->data << " is deleted\n"; 
                 delete currentNode; 
                 return; 
         } 

         // case 3: when both left and right node are present 
         Node* replacementNode =currentNode->right; 
         Node* parentReplacementNode; 

         while (replacementNode->left != NULL) 
                 parentReplacementNode =replacementNode, 
                 replacementNode =replacementNode->left; 
  
         cout << currentNode->data << " is deleted\n"; 
         currentNode->data =replacementNode->data; 

         if (replacementNode->right == NULL) 
         { 
                 delete replacementNode; 
                 parentReplacementNode->left =NULL; 
                 return; 
         } 

         replacementNode->data =replacementNode->right->data; 
         replacementNode->right =NULL; 
         delete replacementNode->right; 
         return; 
 }

 

 int main() 
 { 
    ThreadedBinaryTree tbt;
    tbt.insert(10);
    tbt.insert(12);
    tbt.insert(14);
    
    tbt.inOrder();
 }