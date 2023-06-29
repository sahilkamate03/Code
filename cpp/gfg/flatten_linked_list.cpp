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
Node *flatten(Node *root)
{
   // Your code here
   Node* ans =new Node();
   if (!root->next)
   {
	   Node* temp =ans;
	   while(root)
	   {
		   temp->next =new Node(root->data);
		   temp =temp->next;
		   root =root->next;
	   }
	   return ans->next;
   }

   Node* a =root;
   Node* hp =root->next;
   Node* b =root->bottom;

   Node* temp =ans;
   while(a)
   {
	  temp->next =new Node(a->data);
	  temp =temp->next;

	  while(b)
	  {
		  if (b->data < hp->data)
		  {
			  temp->next =new Node(b->data);
			  temp =temp->next;
		  }
		  else {
			  swap(b,hp);
			  while(b)
			  {
				  temp->next =new Node(b->data);
				  temp =temp->next;

				  if (b->data > hp->data)
				  {
					  swap(b,hp);
				  }
			  }
		  }

	  }
	  a =a->next;
   }

   return ans->next;
}


