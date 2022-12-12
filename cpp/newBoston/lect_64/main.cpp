#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream f;
	f.open("sahil.txt");
	f << "GM sahil!" ;
	// f << ""
	f.close();
}
