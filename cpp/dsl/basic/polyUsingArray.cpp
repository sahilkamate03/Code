#include <bits/stdc++.h>
using namespace std;

class Poly
{
private:
	bool isDegreeInitialised;
	int degree;
	float* coeff;

public:
	Poly(){this->isDegreeInitialised=0;}
	
	Poly(int degree) 
	{
		initialize(degree);
	}

	void initialize(int);
	void print();
	void insertCoeff(int, int);
	void makePoly();
	float evaluate(int);
	void degreeP() {cout << degree << endl;}
	Poly operator+ (Poly&);
	~Poly(){delete[] coeff;}

};

void Poly::initialize(int degree)
{
	this->isDegreeInitialised =1;
	this->degree=degree;
	this->coeff = new float[degree+1];
	fill(coeff, coeff+degree, 0);
}

void Poly::print()
{
	for (int i=degree; i>-1; i--)
	{
		if (coeff[i] == 0) continue;
		if (coeff[i]>0 && i!=degree) 
		{
			cout << " + "<< coeff[i] << "x^" << i << " ";
			continue;
		}
		cout << coeff[i] << "x^" << i << " ";
	}
	cout << endl;
}

void Poly::insertCoeff(int coeff, int power) 
{
	if(!isDegreeInitialised)
	{
		cout << "Enter the degree of polynomial: " << endl;
		int degree;	cin >> degree;
		initialize(degree);
	}

	this->coeff[power] =coeff;
}

void Poly::makePoly()
{
	if(!isDegreeInitialised)
	{
		cout << "Enter the degree of polynomial: ";
		int degree;	cin >> degree;
		initialize(degree);
	}

	cout<< "Enter total non zero element: ";
	int nonZeroElement; cin>> nonZeroElement;
	cout << "Enter first coeff then power." << endl;

	for(int i=0; i<nonZeroElement; i++)
	{
		int power, coeff;
		cout << "> "; cin>> coeff>> power;
		insertCoeff(coeff, power);
	}
}

float Poly::evaluate(int number)
{
	float sum =0;
	for (int i=0; i<=degree; i++)
	{
		if (coeff[i] == 0) continue;
		sum +=(coeff[i] * pow(number,i));
	}

	return sum;
}

Poly Poly::operator + (Poly& poly2)
{
	int minDegree = min(this->degree, poly2.degree);
	int maxDegree = max(this->degree, poly2.degree);
	int minDegreePoly;
	(this->degree<poly2.degree) ? minDegreePoly =0 : minDegreePoly =1;

	Poly result(maxDegree);
	
	for (int i=0; i<=minDegree; i++)
		result.coeff[i] = (this->coeff[i] + poly2.coeff[i]);
	

	for (int i=minDegree+1; i<=maxDegree; i++)
		(minDegreePoly==0) ? result.coeff[i] = poly2.coeff[i] : result.coeff[i] = this->coeff[i];

	return result;
}

int main(){
	Poly p1(2);
	p1.insertCoeff(5,2);
	p1.insertCoeff(4,1);
	p1.insertCoeff(3,0);

	Poly p2(1);
	p2.insertCoeff(2,1);
	p2.insertCoeff(1,0);

	Poly p3 =p1 + p2; 
	p3.print();

}
