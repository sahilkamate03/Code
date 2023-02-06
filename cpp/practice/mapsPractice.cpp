#include <bits/stdc++.h>

using namespace std;

void extraLongFactorials(int n) {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<int> ans;
    ans.push_back(1);
    
    for (int i=2; i<=n; i++){
        int carry=0;
        for (int j=0; j<ans.size(); j++){
            int val = ans[i] * i + carry;
            ans[i] = val%10;
            carry = val/10;
        }
        
        while(carry!=0){
            ans.push_back(carry%10);
            carry/=10;
        }
        
    }
    
    reverse(ans.begin(), ans.end());
    
    for (int i=0; i<ans.size(); i++){
        cout << ans[i];
    }
}

int main()
{
    int n; cin>>n;

    extraLongFactorials(n);
    return 0;
}
