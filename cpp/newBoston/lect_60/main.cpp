#include <iostream>
using namespace std;

template <class T>
class Sahil{
	T first , second;
public:
	Sahil(T a, T b){
		first = a;
		second = b;
	}

	T bigger();
};

template <class T>
T Sahil<T>::bigger(){
	return (first>second ? first : second);
}

int main(){
	Sahil <int> so(40,5);
	cout << so.bigger() << endl;
}
