#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	string data;
	int freq;
	Node* left;
	Node* right;

	Node(string _d, int _f)
	{
		data =_d;
		freq =_f;
		left =nullptr;
		right =nullptr;
	}
};

bool compare(Node* a, Node* b)
{
	return (a->freq > b->freq) ? false : true;
}

Node* huffman(string data[], int freq[], int n)
{
	vector<Node*> arr;
	for (int i=0; i<n; i++)
	{
		Node* newNode =new Node(data[i], freq[i]);
		arr.push_back(newNode);
	}
	
	Node* root =nullptr;

	while (arr.size()>1)
	{
		sort(arr.begin(), arr.end(), compare);
		Node* newNode =new Node(arr[0]->data+arr[1]->data, arr[0]->freq+arr[1]->freq);
		newNode->left =arr[0];
		newNode->right =arr[1];
		arr.push_back(newNode);
		arr.erase(arr.begin(), arr.begin()+2);
	}
	
	return arr[0];	
}

void printCode(Node* root, string data[], int n)
{
	
	for (int i=0; i<n; i++)
	{
		Node* node =root;
		string code ="";
		while(node->data != data[i])
		{
			if (node->left->data.find(data[i]) != string::npos)
				node = node->left,
				code +="0";
			else
				code+="1",
				node =node->right;
		}
		cout << data[i] << " : " << code << "\n";
	}

}

void printMsg(string code, Node* root)
{
	for (int i=0; i<code.size(); i++)
	{
		Node* node =root;
		string data =node->data;
		while(data.size()>1 && i<code.size())
		{
			if ((int)code[i] == 48)
				node =node->left;
			else 
				node =node->right;
			data =node->data;
			i++;
		}
		i--;
		cout << data;
	}
	cout << "\n";
}

int main()
{
	string data[] ={"a","b","c","d","e","f"};
	int freq[] ={5,9,12,13,16,45};
	int n= sizeof(freq)/sizeof(int);

	Node* root=huffman(data, freq, n);
	printCode(root, data, n);
//	printMsg("111001110111111001011100001", root);
}
