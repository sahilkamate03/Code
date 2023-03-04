#include <bits/stdc++.h>
using namespace std;

#define MAP_SIZE 23
int arr[MAP_SIZE];

void initialize()
{
	for (int i=0; i<MAP_SIZE; i++)
		arr[i] =-1;
}

int input()
{
	int value;
	cout << "Enter the value: ";	
	cin >> value;
	return value;
}

int hash_fxn(int key)
{
	return (key%10);
}

void insert()
{
	int value =input();

	int index =hash_fxn(value);
	
	int i=index;
	do
	{
		if (arr[i]==-1)
		{
			arr[i] =value;
			break;
		}
		else i=(i+1) % MAP_SIZE;	
	}while (i!=index);
}

bool search()
{
	int value =input();

	int index =hash_fxn(value);
	
	int i=index;
	do
	{
		if (arr[i]==value)
		{
			return true;
		}
		else i=(i+1) % MAP_SIZE;	
	}while (i!=index);

	return false;
}


void delete_element()
{
	int value =input();

	int index =hash_fxn(value);
	
	int i=index;
	do
	{
		if (arr[i]==value)
		{
			arr[i]=-1;
			break;
		}
		else i=(i+1) % MAP_SIZE;	
	}while (i!=index);
}

void display()
{
	for (int i=0; i<MAP_SIZE; i++)
	{
		if(arr[i]!=-1) cout << arr[i] << " ";	
	}
	cout << endl;
}

void menu()
{
	int option =-1;

	cout << "\n1.Insert \n2.Delete \n3.Search \n4.Display \n5.Quit\n";
	cout << "\nEnter Option: ";
	cin >> option;

	switch(option)
	{
		case 1:
		insert();
		break;

		case 2:
		delete_element();
		break;

		case 3:
		cout << search() << endl;
		break;

		case 4:
		display();
		break;

		default:
		exit(1);

	}
}

int main()
{
	initialize();
	while(true)
	{
		menu();	
	}

}

