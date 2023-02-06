#include <iostream>
using namespace std;

class Enemy{
public:
	int attackPower;
public:
	void setAttackPower(int a) {
		attackPower = a;
	}
};

class Ninja: public Enemy{
public:
	void attack(){
		cout<<"This is ninja chop - " << attackPower << endl;
	}
};

class Monster: public Enemy{
public:
	void attack(){
		cout<<"This is Monster jump - " << attackPower << endl;
	}
};

int main(){
	Ninja n;
	Monster m;

	Enemy *enemy1  = &n;
	Enemy *enemy2  = &m;

	n.setAttackPower(29);
	enemy2->setAttackPower(59);

	n.attack();
	m.attack();
}
