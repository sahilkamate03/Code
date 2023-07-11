/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node *merge(Node *a, Node *b)
{
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data > b->data) swap(a,b);
    Node* res =a;

    while (a != NULL && b != NULL){
        Node *temp =NULL;
        while (a != NULL && a->data <= b->data)
        {
            temp =a;
            a =a->bottom;
        }            
        temp->bottom =b;
        swap(a,b);
    }
    return res;
}

Node *flatten(Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    Node *start =flatten(root->next);
    return merge(root, start);
}


