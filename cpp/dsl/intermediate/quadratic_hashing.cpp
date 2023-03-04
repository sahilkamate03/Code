#include <bits/stdc++.h>
using namespace std;

#define MAP_SIZE 10

struct data
{
	int prn;
	int score;
	
	data()
	{
		prn =-1;
		score =-1;
	}
};

struct c_map
{
	data arr[MAP_SIZE];

	int hash_fxn(int);
	void insert(int, int);
	void multiple_insert(int);
	void remove(int);
	void search(int);
	void display();	
};

int c_map::hash_fxn(int value)
{
	return (value%10);
}

void c_map::insert(int value, int score)
{
	int index =hash_fxn(value);
	
	int count =1;
	int i=index;
	do
	{
		if (arr[i].prn==-1)
		{
			arr[i].prn =value;
			arr[i].score =score;
			break;
		}
		else i= (index+(count * count )) % MAP_SIZE;	
		count++;
	}while (i!=index);
}

void c_map::multiple_insert(int times)
{
    int prn, score;
    cout << "\nEnter (PRN, Score)\n";
    for (int i=0; i<times; i++)
    {
        cout << i+1 <<">> ";
        cin >> prn >> score;
        insert(prn, score);
    }
    cout << endl;
}

void c_map::remove(int value)
{
	int index =hash_fxn(value);
	
	int i=index;
	do
	{
		if (arr[i].prn ==value)
		{
			arr[i].prn=-1;
			arr[i].score=-1;
			break;
		}
		else i=(i+1) % MAP_SIZE;	
	}while (i!=index);
}

void c_map::search(int value)
{
	int index =hash_fxn(value);
	
	int i=index;
	do
	{
		if (arr[i].prn==value)
		{
			cout << "\nPRN\tSCORE\n";
			cout << arr[i].prn << "\t" << arr[i].score << "\n";
			return;
		}
		else i=(i+1) % MAP_SIZE;	
	}while (i!=index);

	cout << "\nNot Found!\n";
    return;
}

void c_map::display()
{
	cout << "\nPRN\tSCORE\n";
	for (int i=0; i<MAP_SIZE; i++)
	{
		cout << arr[i].prn << "\t" << arr[i].score << "\n";
	}
}

void menu(c_map &myMap)
{
	int option =-1;
	
	cout << "\n1.Insert \n2.Delete \n3.Search \n4.Display \n5.Multiple Insert \n6.Quit\n";
	cout << "\nEnter Option: ";
	cin >> option;

	int prn, score;

	switch(option)
	{
		case 1:
		cout << "Insert (PRN, Score): ";
		cin >> prn >> score;
		myMap.insert(prn, score);
		break;

		case 2:
		cout << "Delete (PRN): ";
		cin >> prn;
		myMap.remove(prn);
		break;

		case 3:
		cout << "Search (PRN): ";
		cin >> prn;
		myMap.search(prn);
		break;

		case 4:
		myMap.display();
		break;
		
		case 5:
		int times;
		cout << "No of enteries: ";
		cin >> times;
		myMap.multiple_insert(times);
		break;

		default:
		exit(1);

	}
}

int main()
{
	c_map myMap;

	while(true)
	{
		menu(myMap);	
	}

}

