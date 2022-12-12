#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t, n, q, l, r, x, adder, sum =0;
	cin>>t;
	while(t--){
		sum =0;
	    cin >> n >>q;
	    for (int i=0; i<n; i++) cin>>x , sum+=x;
	    
	    while(q--){
	        cin >>l >>r;
			if ((l-r)%2 ==0) sum++;
	    }

	    cout << sum << endl;
	}
	
	return 0;

}
