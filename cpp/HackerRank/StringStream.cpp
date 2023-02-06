#include <iostream>
using namespace std;

int main(){
	
	string s = "23,4,23";
	char c;
	for (int i=0; i < s.size(); i++){
		c = s.at(i);
		if (c==',')
			cout << endl;
		else
			cout<<s.at(i);
	}
	
}
