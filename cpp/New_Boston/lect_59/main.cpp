#include <iostream>
using namespace std;

template <class First, class Second>
First add(First a, Second b){
	return a+b;
}

int main(){
	cout << add(7,4.8) <<endl;
}
