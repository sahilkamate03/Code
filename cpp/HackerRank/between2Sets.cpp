#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int num_limit = 101;
	int ans=0;

	// arr size of 
	int n, m; cin >> n >> m;
	int a[n]; int b[m];

	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<m; i++) cin >> b[i];

	int arr1[num_limit] = {0};
	

	for (int j=0; j<m; j++)
	{
		int temp = b[j];
		// int y = b[0];54
		for (int i=1; i<=temp; i++)
		{
			if (temp%i==0) arr1[i]++; 
		}

		
	}

	// for (int i=0; i<num_limit; i++) cout << arr1[i] << " ";

	for (int j=0; j<num_limit; j++)
	{
		int temp =0;
		if (arr1[j] >= m)
			temp = j;
		if (temp==0) {continue;}

		int check=0;
		for (int i=0; i<n; i++)
		{
			// cout << temp << " " << a[i] << endl;
			if (temp%a[i]==0)
				check++;
		}
		// cout << check << endl;
		if (check==n) ans++;		
	}

	cout << ans << endl;

}
