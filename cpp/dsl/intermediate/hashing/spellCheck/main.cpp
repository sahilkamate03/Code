#include <bits/stdc++.h>
#include "linkedList.h"
#include "hashing.h"

using namespace std;
string appendString ="";

void initialize(hashTable &ht)
{
	string s;
	fstream inputFile;
    inputFile.open("input.txt",ios::in); 
    if (inputFile.is_open()){ 
		string line;
		while (getline(inputFile, line))
			s +=line +" ";
		inputFile.close(); 
     }
    
    stringstream iss(s);
    string word;

    while (iss >> word)
    {
    	string cleanWord="";
    	for (char ch : word)
    	{
    		int c =(int) ch;
    		if (c>96 && c<123)
				cleanWord +=ch;
			else if (c>64 && c<91)
				cleanWord +=ch;
    	}
        ht.insert(cleanWord);
    }
}

void destroy()
{
	ofstream file("input.txt", ios::app); 
    if (file.is_open()) { 
        file << appendString << endl; 
        file.close(); 
    }
}

void menu(hashTable &ht)
{
	cout << "\n1.Insert\n2.Display\n3.Spell Check\n4.Quit\n";
	cout << "\nOption: ";
	int choice{-1}; cin>>choice;
	string word; bool isWordPresent;

	switch(choice)
	{
	case 1:
		cout << "Enter word: "; cin>>word;
		ht.insert(word);
		appendString+=(" " + word);
		break;

	case 2:
		ht.display();
		break;

	case 3:
		cout << "Enter word: "; cin>>word;
		isWordPresent =ht.spellCheck(word);

		if (isWordPresent) 
			cout << "Present\n";
		else 
			cout << "Not Present\n", appendString+=(" " + word), ht.insert(word);

		break;

	default:
		destroy();
		exit(0);
	}
	cout << "\n";
}

int main(){
	hashTable ht;

	initialize(ht);
	while (true)
		menu(ht);

	return 0;

}
