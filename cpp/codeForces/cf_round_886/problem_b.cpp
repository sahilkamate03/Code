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
        int n;
        cin >>n;

        int ans =-1;
        int max =-1;
        for (int i=0; i<n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a<=10 && b>max)
                max =b, ans = i+1;
        }
        cout << ans << endl;
    }
}

