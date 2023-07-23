#include <bits/stdc++.h>
using namespace std;

int solve(long long int c, int n, vector<long long int> &v)
{
    int l=1, r =1e9;
    while (l <= r) {
        long long int m = l + (r - l) / 2;
        long long int sum =0;
        for (int i=0; i<n; i++)
        { 
            sum +=((v[i] + 2*m) * (v[i] + 2*m));
            if (sum > c) break;
        }
        if (sum==c)
            return m;
 
        if (sum < c)
            l = m + 1;
 
        else
            r = m - 1;
    }
 
    return -1;
}

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
    	int n; long long int c;
        cin >>n >> c;

        vector<long long int> v;
        for (int i=0; i<n; i++)
        {
            long long int temp; cin>>temp;
            v.push_back(temp);
        }

        cout << solve(c, n, v) << endl ;
    }
}

