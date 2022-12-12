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
	    int n, x, y;
	    cin >> n >>x >>y;
	    string ans = "NO";
	    for (int i=2; i<=n; i++){
	        if (x*i == y) {
	        	ans = "YES";
	        	break;
	        }
	    }
	    if (y==0) ans = "YES";
	    cout << ans << endl;
	}
}
