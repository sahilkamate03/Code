#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
	    int n, count =0;
	    string x;
	    cin >>n;

	    cin >> x;
	    int t = x[0];
	    for (int i=1; i<n ;i++){
	    	if (t>x[i]) count++;
	    	t = x[i];
	    }
	    cout << count << endl;
	}
	
	return 0;
}
