#include <bits/stdc++.h>
#include <iostream>

using namespace std;



#include <vector>


int main(){ 
    vector <int> a {7,7,3,3};
    sort(a.begin(), a.end());
    int x,b,c;
    
    int z=(a[2]-a[1]+a[1]-a[0]);
 
    for(int i{0};i<a.size()-2;i++){
        x=a[i+2]-a[i+1];
        b=a[i+1]-a[i];
        c=x+b;
                
                
        if(z>c){
            z=c;
            
        }
    }
    cout<<z;

}