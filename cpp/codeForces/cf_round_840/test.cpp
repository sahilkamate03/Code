#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t; // read number of test cases

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int h[n], p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        while (true)
        {
            // find minimum power monster
            int min_power = 1e9;
            for (int i = 0; i < n; i++)
            {
                if (h[i] > 0 && p[i] < min_power)
                {
                    min_power = p[i];
                }
            }
            // subtract min power from k
            k = k - min_power;
            // find number of monsters that can be killed
            int num_monsters_killed = 0;
            for (int i = 0; i < n; i++)
            {
                if (h[i] > 0)
                {
                    num_monsters_killed += h[i] / k;
                }
            }
            // reduce health of these monsters
            for (int i = 0; i < n; i++)
            {
                if (h[i] > 0)
                {
                    h[i] = h[i] - num_monsters_killed * k;
                }
            }
            // check if all monsters are killed
            bool all_monsters_killed = true;
            for (int i = 0; i < n; i++)
            {
                if (h[i] > 0)
                {
                    all_monsters_killed = false;
                    break;
                }
            }
            if (all_monsters_killed)
            {
                cout << "YES" << endl;
                break;
            }
            // check if k <= 0
            if (k <= 0)
            {
                cout << "NO" << endl;
                break;
            }
        }
    }

    return 0;
}