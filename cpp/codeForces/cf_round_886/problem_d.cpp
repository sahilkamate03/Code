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
    	int n, k;
        cin >> n>> k;
        vector<int> temp;
        for (int i=0; i<n; i++)
        {
            int a; cin>>a;
            temp.push_back(a);
        }

        sort(temp.begin(), temp.end());

        int i=1;
        int m =0;
        for (int j =1; j<n; j++)
        {
            if (temp[j] -temp[j-1] <= k)
                i++;
            else
                m = max(m,i),
                i =1;
        }
        m = max(m,i);
        cout << n -m << endl;
    }
}

