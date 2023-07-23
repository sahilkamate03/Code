
#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while (t--)
    {
    	string ans;
        for (int i=0;i<8; i++)
        {
        	for (int j=0; j<8; j++)
        	{
        		char c;
        		cin >> c;
        		if (c != '.')
        			ans +=c;
        	}
        }
        cout << ans << endl;
    }
}

