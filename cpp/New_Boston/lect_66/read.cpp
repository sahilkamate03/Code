#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream s("player.txt");

	int playerId;
	string Name;
	float money;

	while(s >> playerId >> Name >> money) {
		cout << playerId << "," << Name  << "," << money <<endl;
	}
}
