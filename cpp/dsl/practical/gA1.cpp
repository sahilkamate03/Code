#include <bits/stdc++.h>
using namespace std;

class Game
{
private:
	int badiPlayerCount, cricketPlayerCount, footballPlayerCount;
	int *badiPlayerNumber, *cricketPlayerNumber, *footballPlayerNumber;

	int* unionSet(int, int);
	int* intersectionSet(int, int);
	
	void menu();

public:
	Game() 
	{
		badiPlayerCount =0;
		cricketPlayerCount =0;
		footballPlayerCount =0;
	}

	Game (int badiPlayerCount, int cricketPlayerCount, int footballPlayerCount)
	{
		this->badiPlayerCount =badiPlayerCount;
		this->cricketPlayerCount =cricketPlayerCount;
		this->footballPlayerCount =footballPlayerCount;
	}

	~Game()
	{
		delete[] badiPlayerNumber;
		delete[] cricketPlayerNumber;
		delete[] footballPlayerNumber;
	}

	void badiBuilder(int);
	void cricketBuilder(int);
	void footballBuilder(int);

	int getBadiPlayerCount();
	int getCricketPlayerCount();
	int getFootballPlayerCount();

	void callUnion();
	void callIntersection();	
};

int* Game::unionSet(int a1, int b1)
{
	int *a, *b ,n ,m;
	switch (a1)
	{
	case 1:
		a =badiPlayerNumber;
		n =badiPlayerCount;
		break;
	case 2:
		a =cricketPlayerNumber;
		n =cricketPlayerCount;
		break;
	case 3:
		a =footballPlayerNumber;
		n =footballPlayerCount;
		break;
	}

	switch (b1)
	{
	case 1:
		b =badiPlayerNumber;
		m =badiPlayerCount;
		break;
	case 2:
		b =cricketPlayerNumber;
		m =cricketPlayerCount;
		break;
	case 3:
		b =footballPlayerNumber;
		m =footballPlayerCount;
		break;
	}

	int size =n+m;
	int *result =new int[size];
	fill(result, result+size, 0);

	for (int i=0; i<n; i++)
		result[i] =a[i];

	int count =0;
	for (int i=0; i<m; i++)
	{
		bool present  =false;
		int key =b[i];

		for (int j=0; j<n ;j++)
		{
			if (a[j]==key) 
			{
				present =true; 
				break;
			}
		}

		if (!present) result[n+count]=key, count++;
	}

	return result;
}

void Game::menu()
{
	cout << endl << "Select option." << endl;
	cout << "1. Badminton" << endl;
	cout << "2. Cricket" << endl;
	cout << "3. Football" << endl << endl;
}

int* Game::intersectionSet(int a1, int b1)
{
	int *a, *b ,n ,m;
	switch (a1)
	{
	case 1:
		a =badiPlayerNumber;
		n =badiPlayerCount;
		break;
	case 2:
		a =cricketPlayerNumber;
		n =cricketPlayerCount;
		break;
	case 3:
		a =footballPlayerNumber;
		n =footballPlayerCount;
	}

	switch (b1)
	{
	case 1:
		b =badiPlayerNumber;
		m =badiPlayerCount;
		break;
	case 2:
		b =cricketPlayerNumber;
		m =cricketPlayerCount;
		break;
	case 3:
		b =footballPlayerNumber;
		m =footballPlayerCount;
	}

	int size =n+m;
	int *result =new int[size];
	fill(result, result+size, 0);

	int count=0;
	for (int i=0; i<n ;i++)
	{
		for (int j=0; j<m; j++)
		{
			if (b[j]==a[i]) 
			{
				result[count] =a[i];
				count++;
				break;
			}
		}
	}
	return result;
}

void Game::badiBuilder(int badiPlayerCount=0)
{
	if (badiPlayerCount == 0)
	{
		cout << "Enter total number of badi player: ";
		cin >> badiPlayerCount;
		this->badiPlayerCount =badiPlayerCount;
	}

	badiPlayerNumber = new int[badiPlayerCount];

	cout << "Enter the roll no of badi player: ";

	for (int i=0; i<badiPlayerCount; i++)
		cin >> badiPlayerNumber[i];

	cout <<endl;
}

void Game::cricketBuilder(int cricketPlayerCount=0)
{
	if (cricketPlayerCount == 0)
	{
		cout << "Enter total number of cricket player: ";
		cin >> cricketPlayerCount;
		this->cricketPlayerCount =cricketPlayerCount;
	}

	cricketPlayerNumber = new int[cricketPlayerCount];

	cout << "Enter the roll no of cricket player: ";

	for (int i=0; i<cricketPlayerCount; i++)
		cin >> cricketPlayerNumber[i];

	cout <<endl;
}

void Game::footballBuilder(int footballPlayerCount=0)
{
	if (footballPlayerCount == 0)
	{
		cout << "Enter total number of football player: ";
		cin >> footballPlayerCount;
		this->footballPlayerCount =footballPlayerCount;
	}

	footballPlayerNumber = new int[footballPlayerCount];

	cout << "Enter the roll no of football player: ";

	for (int i=0; i<footballPlayerCount; i++)
		cin >> footballPlayerNumber[i];

	cout <<endl;
}

void Game::callUnion()
{
	int n, m;
	menu();
	int set1 =0, set2 =0;

	cout << "Set1: "; cin >>set1;
	cout << "Set2: "; cin >>set2;

	switch (set1)
	{
	case 1:
		n =badiPlayerCount;
		break;
	case 2:
		n =cricketPlayerCount;
		break;
	case 3:
		n =footballPlayerCount;
		break;
	}

	switch (set2)
	{
	case 1:
		m =badiPlayerCount;
		break;
	case 2:
		m =cricketPlayerCount;
		break;
	case 3:
		m =footballPlayerCount;
		break;
	}

	cout << "Union: ";
	int *ansUnion =unionSet(set1, set2);
	for (int i=0; i<n+m; i++)
		if (ansUnion[i] !=0 ) cout << ansUnion[i] << " ";
	cout << endl;
	delete[] ansUnion;
}

void Game::callIntersection()
{
	int n, m;
	menu();
	int set1 =0, set2 =0;

	cout << "Set1: "; cin >>set1;
	cout << "Set2: "; cin >>set2;

	switch (set1)
	{
	case 1:
		n =badiPlayerCount;
		break;
	case 2:
		n =cricketPlayerCount;
		break;
	case 3:
		n =footballPlayerCount;
		break;
	}

	switch (set2)
	{
	case 1:
		m =badiPlayerCount;
		break;
	case 2:
		m =cricketPlayerCount;
		break;
	case 3:
		m =footballPlayerCount;
		break;
	}

	cout << "Intersection: ";
	int* ansIntersection =intersectionSet(set1, set2);
	for (int i=0; i<n+m; i++)
		if (ansIntersection[i] !=0 ) cout << ansIntersection[i] << " ";
	cout << endl;
	delete[] ansIntersection;
}

int main(){
	Game g1;

	g1.badiBuilder();
	g1.cricketBuilder();
	g1.footballBuilder();
	
	g1.callUnion();
	g1.callIntersection();
}
