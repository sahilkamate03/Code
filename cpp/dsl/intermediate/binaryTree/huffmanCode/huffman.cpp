#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
	int freq;
	string data;
	Node* left;
	Node* right;

public:
	Node() : data{""}, freq{0}, left{nullptr}, right{nullptr} {}
	Node(string _data, int _freq) : data{_data}, freq{_freq}, left{nullptr}, right{nullptr} {}
	friend class HuffmanTree;
};

class HuffmanTree
{
private:
	Node* root;
	vector<Node*> nodes;
public:
	string dataString;
	HuffmanTree() : root{nullptr} {}

	void Huffman();
	static bool compare(Node*, Node*);
	void HuffmanTreeBuilder();
	void printCode(string);
	void printString(string);
};

void HuffmanTree::printCode(string ch)
{
	Node* currentNode =root;
	string huffmanCode ="";

	while(currentNode && currentNode->data != ch)
	{
		if (currentNode->left && currentNode->left->data.find(ch) != std::string::npos)
		{
			huffmanCode +="0";
			currentNode =currentNode->left;
		}
		else if (currentNode->right && currentNode->right->data.find(ch) != std::string::npos)
		{
			huffmanCode +="1";
			currentNode =currentNode->right;
		}

		else {
			break;
		}
	}
	cout << huffmanCode;
	// cout << ch << " " << huffmanCode << endl ;
	
}

void HuffmanTree::printString(string binaryInputString)
{
	binaryInputString+="0";
	Node* currentNode =root;
	Node* prevNode =nullptr;

	for (int i=0; i<binaryInputString.size(); i++)	
	{	
		prevNode =currentNode;
		string tempChar; tempChar = binaryInputString[i]; 

		if (tempChar=="0")
			currentNode =currentNode->left;
		else if (tempChar == "1")
			currentNode =currentNode->right;

		if (!currentNode)
			currentNode =root, --i,
			cout << prevNode->data;
	}
}

bool HuffmanTree::compare(Node* Node1, Node* Node2)
{
	return Node1->freq < Node2->freq;
}

void HuffmanTree::HuffmanTreeBuilder()
{
	while(nodes.size() != 1)
	{
		sort(nodes.begin(), nodes.end(), compare);

		Node* Node1 =nodes[0];
		Node* Node2 =nodes[1];

		string newData =Node1->data + Node2->data;
		int newFreq =Node1->freq + Node2->freq;

		Node* newNode =new Node(newData, newFreq);
		newNode->left =Node1;
		newNode->right =Node2;
	
		if (nodes.size()==2)
			root =newNode;
		
		nodes.erase(nodes.begin());
		nodes.erase(nodes.begin());
		nodes.push_back(newNode);
	}
}

void HuffmanTree::Huffman()
{
	string data[dataString.size()];
	int freq[dataString.size()];

	for (int i=0; i<dataString.size(); i++)
	{
		char ch =dataString[i];
		int freqCount =0;

		for (int j=0; j<dataString.size(); j++)
		{
			if (dataString[i]==ch)
				freqCount++;
		}

		data[i] =ch;
		freq[i] =freqCount;
	}

	// for (i = 0; i < dataString.size(); i++) {
    //     freq[dataString[i]]++;
    // }
	for (int i=0; i<dataString.size(); i++)
	{
		string _data =data[i]; int _freq =freq[i];
		Node* newNode = new Node(_data, _freq);
		nodes.push_back(newNode);
	}

	HuffmanTreeBuilder();

	for (int i=0; i<dataString.size(); i++)
	{
		string temp ="";
		temp +=dataString[i];
		printCode(temp);	
	}
}


void Menu()
{
	HuffmanTree hmt;

	cout <<"Huffman Encoding and Decoding";

	while (true)
	{
		string userInputString;
		string binaryInputString;

		cout << "\n\n1.Encode\n2.Decode\n3.Exit\n";
		cout << ">>";

		int choice; cin >>choice;
		cout << endl;
			
		if (choice==1){
			cout << "Enter the string.\n";
			cin.ignore();
			getline(cin, userInputString);
			hmt.dataString =userInputString;
			hmt.Huffman();
		}
		else if (choice == 2) 
		{
			cout << "Enter the binary.\n";
			cin.ignore();
			getline(cin, binaryInputString);
			hmt.printString(binaryInputString);
		}
		else {
			exit(0);
		}
	}
}

int main()
{
	Menu();
}