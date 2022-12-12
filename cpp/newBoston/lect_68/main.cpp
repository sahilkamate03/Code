#include <iostream>
#include <fstream>
using namespace std;

int health;

int getWhatTheyWant();
void displayItem (int x);

// main function
int main(){
	health = 0;
	int whatTheyWant;

	whatTheyWant = getWhatTheyWant();

	while (whatTheyWant !=4 ){

		switch (whatTheyWant) {
			case 1:
				displayItem(1);
				break;
			case 2:
				displayItem(2);
				break;
			case 3:
				displayItem(3);
				break;
		}
		whatTheyWant = getWhatTheyWant();
	}
}

int getWhatTheyWant() {
	int choice;
	cout << "\n1 - just plain items" << endl;
	cout << "2 - helpful items" << endl;
	cout << "3 - harmful items" << endl;
	cout << "4 - quit program\n" << endl;

	cin >> choice;
	cout << endl;
	return choice;
}

// display items function
void displayItem(int x) {

	ifstream f("game_data.txt");
	string name;
	double energy;

	if (x==1){
		while (f >> name >> energy){
			if (energy == 0){
				cout << name << " " << energy << endl;
				health += energy;
			}
		}
		cout << endl;
		cout << health << endl;
		cout << endl;
	}

	if (x==2){
		while (f >> name >> energy){
			if (energy > 0){
				cout << name << " " << energy << endl;
				health += energy;
				
			}
		}
		cout << endl;
		cout << health << endl;
		cout << endl;
	}

	if (x==3){
		while (f >> name >> energy){
			if (energy < 0){
				cout << name << " " << energy << endl;
			}
		}
		cout << endl;
		cout << health << endl;
		cout << endl;
	}

}