#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,size,count;
	cin>>n;
	count=0;
	while(n--){
	    cin>>size;
	    int arr[size];
	    for (int i=0;i<size;i++){
	        cin>>arr[i];
	    }
	    int a[size];
	    for (int i=0;i<size;i++){
	        a[i]=arr[i];
	    }
	   // sort(a);
	   int n = sizeof(a)/sizeof(a[0]); 
        sort(a, a+n);
	    for (int i=0;i<size-1;i++){
	        if (arr[i]>arr[i+1]){
	            swap(arr[i],arr[i+1]);
	            count+=1;
	        }
	    
	    if (count==0){
	        cout<<"yes"<<endl;
	    }
	    else if (a==arr){
	                cout<<"yes"<<endl;
	            }else{
	                cout<<"no"<<endl;
	            }
	    }
	}
	
	return 0;
}
