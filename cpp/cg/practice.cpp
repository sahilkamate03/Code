#include <iostream>
#include <string>
using namespace std;

class Student{

private:	
	string name;
	int roll_no;
	
public:	

	//setter
	void set_value(string name, int roll_no){
		name = name;
		roll_no = roll_no;
	}

	//getter
	void display(){
		cout << "name: " << name << endl;
		cout << "roll_no: " << roll_no << endl;
	}
	
};

int main(){

	cout << "hello" << endl;
	Student s;
	s.set_value("sahil", 46);
	s.display();
	// cout << s.name << endl << s.roll_no;
	
}
