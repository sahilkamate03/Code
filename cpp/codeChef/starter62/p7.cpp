#include <bits/stdc++.h>
using namespace std;

int main() {
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	// cout << pow(2,4) << endl;
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin >>n;
	    int a =-1 , b=-1;
	    // string ans = "YES";
	    for (int i=0; i<n; i++){
	    	for (int j =0; j<n; j++){
	    		if (pow(i,2) + pow(j,2) == n) {
	    			a =i, b=j;
	    			break;
	    		}
	    	}
	    }

	    (a != -1) ? cout << b << " " << a << endl : cout << -1 << endl;

	}
	
	return 0;
}
