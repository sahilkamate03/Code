#include <bits/stdc++.h>
using namespace std;
#define MAX 65536

class node
{
	int data;
	node* llink,*rlink;
	bool lthr,rthr;
	public:
	node()
	{
		llink=NULL;
		rlink=NULL;
		lthr=1;
		rthr=1;
	}
	node(int d)
	{
		data=d;
		llink=NULL;
		rlink=NULL;
		lthr=1;
		rthr=1;
	}
	node(node *dm)
	{
		data=MAX;
		llink=dm;
		rlink=dm;
		lthr=1;
		rthr=1;
	}
	friend class bst;
};

class bst
{
	node *dum,*root;
	public:
	bst()
	{
		dum=new node(dum);
		dum->llink=root;
		root=NULL;
	}
	void disp();
	void insert_bst(int val);
	void convert(node *root);
	node* getroot()
	{
		return root;
	}
	node* in(node* root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else
	{
		in(root->llink);
		cout<<root->data<<"("<<root->lthr<<","<<root->rthr<<")"<<endl;
		in(root->rlink);
	}
	return NULL;
}


};

void bst :: insert_bst(int val)
{
	if(root==NULL)
	{
		node *p=new node(val);
		root=p;
		root->llink=NULL;
		root->rlink=NULL;
		return;
	}
	node *p=new node(val);
	node *tmp=root;
	while(1)
	{
		if(tmp->data>val)
		{
			if(tmp->llink==NULL)
				break;
				tmp=tmp->llink;
		}
		else
		{
			if(tmp->rlink==NULL)
				break;
			tmp=tmp->rlink;
		}
	}
	if(tmp->data>val)
	{
		tmp->llink=p;
		
	}
	else
		tmp->rlink=p;
	
}

void bst :: convert(node *root)
{
	vector<node*> v;
	stack<node*> st;
	node* tmp=root;
	while(tmp!=NULL || !st.empty())
	{
		while(tmp!=NULL)
		{
			st.push(tmp);
			tmp=tmp->llink;
		}
		tmp=st.top();
		v.push_back(tmp);
		st.pop();
		tmp=tmp->rlink;	
	}
	int n=v.size();
	v[0]->llink=dum;
	v[n-1]->rlink=dum;
	dum->rthr = false; // Set right thread of dum to false
    dum->rlink = v[n-1];
	
	for(int i=0;i<v.size();i++)
	{
		if(i)
		{
			if(v[i]->llink==NULL)
			{
				v[i]->llink=v[i-1];
			}
			else
			{
				v[i]->lthr=false;
			}
		}
		if(i!=n-1)
			{
			if(v[i]->rlink==NULL)
			{
				v[i]->rlink=v[i+1];
			}
			else
			{
				v[i]->rthr=false;
			}
		}
			
	}
}

int main()
{
	bst b;
	b.insert_bst(10);
	b.insert_bst(1);
	b.insert_bst(23);
	
	b.convert(b.getroot());
//	b.in(b.getroot());
	b.display();
	//b.disp();
	
}
