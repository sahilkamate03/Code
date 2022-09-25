#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream s("player.txt");

	cout << "Enter Player Id, Name, Money" << endl;
	cout << "Press ctrl + z to exit." << endl;

	int playerId;
	string Name;
	float money;

	while (cin >> playerId >> Name >> money){
		s << playerId << " " << Name << " " << money << endl;
	}

}
