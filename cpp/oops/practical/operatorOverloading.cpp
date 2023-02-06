#include <bits/stdc++.h>
using namespace std;


class cmplx
{
float real , imag;      
        
public :
     cmplx()
     {
        real = 0;
        imag = 0;
     }
     
     cmplx(float tempx , float tempy)
     {
        real = tempx;
        imag = tempy;
     }
     
     cmplx operator + (cmplx &temp)
     {
     	cmplx result;
     	this->putdata();
     	result.real =this->real + temp.real;
     	result.imag =this->imag + temp.imag;
     	return result;
     }

     cmplx operator - (cmplx);
     cmplx operator * (cmplx);
     cmplx operator / (cmplx);                
     
     void getdata()
     {
        cout<<"enter real and imaginary part of complex number ";
        cin>>real>>imag;                   
     } 
     
     void putdata()
     {
        cout<<real<<" "<<imag<<endl;
     }   
     
     friend istream & operator >>( istream & , cmplx &);     
     friend ostream & operator <<( ostream & , cmplx &);                                                     
};

istream & operator >>( istream & mycin, cmplx & t)             
{
    mycin >> t.real >> t.imag;
    return mycin;
}


int main(){
	cmplx c3(9,9);
    cmplx c1(1,1);
    cmplx result(c1 +c3);

    // result =c1 +c3;
    // result.putdata();
}
