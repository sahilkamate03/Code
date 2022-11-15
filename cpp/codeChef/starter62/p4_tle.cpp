#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t, n, q, l, r, adder, sum;
	cin>>t;
	while(t--){
	    cin >> n >>q;
	    int arr[n];
	    for (int i=0; i<n; i++) cin>>arr[i];
	    
	    while(q--){
	        adder =1;
	        cin >>l >>r;
	        
	        for (int j=l-1; j<r; j++ ) arr[j] +=adder, adder *=-1;
	    }
	    
	    sum =0;
	    while (n--) sum+=arr[n];
	    
	    cout << sum << endl;
	}
	
	return 0;

}
	