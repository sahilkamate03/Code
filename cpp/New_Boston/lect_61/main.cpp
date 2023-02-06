#include <iostream>
using namespace std;

template <class T>
class Sahil{ 
public:
	Sahil (T x)	{
		cout << x << " this is not char!" << endl;
	}
};

template <>
class Sahil<char>{
public:
	Sahil (char x) {
		cout << x << " this is char!" << endl;
	}

};
int main(){
	Sahil<int> so(3);
	Sahil<char> so1('s');
	int x;
	cin >> x; 
}
