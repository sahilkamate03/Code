#include <bits/stdc++.h>
using namespace std;

int main() {
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		// init var
	    int n,k; cin >> n >> k; 

	    // init bool
	    bool last = false; bool present = false;
	    for (int i=0; i<n; i++) {
	    	int x; cin >> x;
	    	if (n!=1 && i==n-1 && x==k && !present) last =true;
	    	if (x==k) present=true;
	    }
	    
	    if (!last && present) cout << "Yes" << endl;
	    else cout << "No" << endl;
	}
	
	return 0;
}
