#include <bits/stdc++.h>
using namespace std;

class AbstractEmployee {
	virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
protected:
	string Name;
	string Company;
	int Age;

public:
	// Employee(){}

	Employee (string name, string company, int age){
		Name = name;
		Company = company;
		Age = age;
	}

	// setter
	void set_value(string Name, string Company, int Age){
		Name = Name;
		Company = Company;
		Age = Age;
	}

	// getter
	void getInfo(){
		cout << "Name: " << Name << endl;
		cout << "Company: " << Company << endl;
		cout << "Age: " << Age << endl;
	}

	void AskForPromotion(){
		if (Age>30)
			cout << "you got promotion." << endl;
		else
			cout << "no promotion try later." << endl;
	}

	void Work(){
		cout << Name << " is checking email " << endl;
	}
};

class Developer : public Employee{
public:
	string FavProgrammingLanguage;

	Developer (string name, string company, int age, string favProgrammingLanguage)
		:Employee(name, company, age){
		FavProgrammingLanguage = favProgrammingLanguage;
	}

	void FixBug(){
		getInfo();
		cout << "fixed bug using " << FavProgrammingLanguage << endl;
	}

	virtual void Work(){
		cout << Name << " is writting codes. Heavy Coder." << endl;
	}
};

class Teacher : public Employee{
private:
	string Subject;

public:
	Teacher(string name, string company, int age, string subject)
	:Employee(name, company, age)
	{
		Subject = subject;
	}

	void PrepareLesson(){
		getInfo();
		cout << "is preparing from " << Subject << endl;
	}

	void Work(){
		cout << Name << " is teaching " << Subject << endl;
	}
};

int main(){
	// Employee emp1("Sahil", "SK", 46);
	// emp1.getInfo();
	// emp1.AskForPromotion();

	Developer dev1("Sahil", "SK", 19, "Python");
	// dev1.FixBug();
	// dev1.AskForPromotion();

	Teacher teach1("Jack", "RJ", 50, "CS");
	// teach1.PrepareLesson();
	// teach1.AskForPromotion();

	// dev1.Work();
	// teach1.Work();

	// Employee class can hold pointer of derieved class
	// Employee *e1 = &dev1;
	// Employee *e2 = &teach1;

	// it first check Work fxn in derieved classes if
	// in Employee class has declared Word as virtual else
	// it will Employee class Work
	// e1->Work();
	// e2->Work();

	Employee e1 = dev1;
	Employee e2 = teach1;

	dev1.Work();
	teach1.Work();
}