#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
        double res =1; 
        m--, n--;
        int j=1;
        for (int i=m+n; i>min(m,n); i--)    
            res=res*(i/j++);

        return (int) res;
    }

int main()
{
	uniquePaths(3,7);
	return 0;
}