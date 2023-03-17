#include <bits/stdc++.h>
using namespace std;

#define MAP_SIZE 23

struct node
{
	int prn;
	int score;
	int link;

	node()
	{
		prn =-1;
		score =-1;
		link =-1;
	}
};

struct c_map
{
	struct node arr[MAP_SIZE];

	int hash_fxn1(int);
	int hash_fxn2(int);
	void put(int, int, int);
	int linear_insert(int, int, int);
	void insert(int, int);
	void multiple_insert(int);
	void remove(int);
	void search(int);
	void display();
};

int c_map::hash_fxn1(int value)
{
	return (value%10);
}

int c_map::hash_fxn2(int value)
{
	return ((value*9)%MAP_SIZE);
}

void c_map::put(int index, int prn, int score)
{
	arr[index].prn =prn;
	arr[index].score =score;
	arr[index].link =-1;
}

int c_map::linear_insert(int index, int prn, int score)
{
	while (arr[index].prn != -1)
	{
		index = (index+1) % MAP_SIZE;
	}
	arr[index].prn =prn;
	arr[index].score =score;
	
	return index;
	
}

void c_map::insert(int prn, int score)
{
	int index =hash_fxn1(prn);
	int i =index;

	if (arr[i].prn==-1)
	{
		put(i, prn, score);
		return;
	}

	if (hash_fxn1(arr[i].prn) != hash_fxn1(prn))
	{
		int temp_prn =arr[i].prn;
		int temp_score =arr[i].score;

		int position =linear_insert(i, temp_prn, temp_score);
		arr[i].link =position;
		arr[i].prn =prn;
		arr[i].score =score;
		return;
	}

	if (hash_fxn1(arr[i].prn) == hash_fxn1(prn))
	{
		do
		{
			i =(i+1) % MAP_SIZE;
		} while( hash_fxn1(arr[i].prn) != hash_fxn1(prn) && i != index );

		if (i==index)
			linear_insert(i, prn, score);
		else
		{
			while(arr[i].link != -1)
			{
				i =arr[i].link;
			}

			int l = linear_insert(i, prn, score);
			arr[i].link =l;		
		}
		return;

	}

	while(arr[i].link != -1)
	{
		i =arr[i].link;
	}

	int l = linear_insert(i, prn, score);
	arr[i].link =l;

	return;
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


void c_map::remove(int prn)
{
	int index =hash_fxn(prn);
	int i =index;

	do 
	{
		if (arr[i].prn == prn)
		{
			arr[i].prn =-1;
			arr[i].score =-1;
			arr[i].link =-1;
			return;
		}

		i = (i+1) % MAP_SIZE;
	} while(index != i);


}

void c_map::search(int prn)
{
	int index =hash_fxn(prn);
	int i =index;

	do 
	{
		if (arr[i].prn == prn)
		{
			cout << "\nPRN\tSCORE\tLINK\n";
			cout << arr[i].prn << "\t" << arr[i].score << "\t" << arr[i].link << "\n";
			return;
		}

		i = (i+1) % MAP_SIZE;
	} while(index != i);

	cout << "Not Found\n";
}

void c_map::display()
{
	cout << "PRN\tSCORE\tLINK\n";
	for (int i=0; i<MAP_SIZE; i++)
	{
		if (arr[i].prn == -1)
			continue;
		cout << arr[i].prn << "\t" << arr[i].score << "\t" << arr[i].link << "\n";
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

	while (true)
		menu(myMap);
}
