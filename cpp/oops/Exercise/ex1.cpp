#include <bits/stdc++.h>
using namespace std;

class Shape{
protected:
	float _height;
	float _width;
public:
	void set_data(float height,float width){
		_height = height;
		_width = width;
	}

};

class Triangle : public Shape {
public:
	float area(){
		return (_width * _height)/2 ;
	}
};

class Rectangle : public Shape {
public:
	float area(){
		return (_width * _height) ;
	}
};

int main(){
		
	Triangle tri;
	tri.set_data(10,20);

	Rectangle rect;
	rect.set_data(2.4, 4.9);
	
	cout << "Area of triangle: " << tri.area() << endl;
	cout << "Area of rectangle: " << rect.area() << endl;
}
