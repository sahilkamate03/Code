#include <bits/stdc++.h>
using namespace std;

int power(int base, int time)
{
	int ans = 1;
	while(time--){
		ans *=base;
	}

	return ans;
}

void answer(int m, int s)
{	
	if (s==0 && m==1) {cout << 0 << " " << 0 << endl; return;}

	if (s > (9*m) || s==0)
	{
		cout << -1 << " " << -1 << endl;
		return;
	}

	string ans_min ="";

	int decreaser = (9*m) - s;
	string ans_max ="";
	int location =0;

	int decreaser_max = decreaser;

	int sub_min;
	int decreaser_min = decreaser;

	if (decreaser>9)
		sub_min =8, decreaser_min -=sub_min;
	else 
		sub_min = decreaser, decreaser_min=0;

	for (int runner=0; runner<m; runner++)
	{	
		// for calc min
		ans_min += to_string(9-sub_min);

		if (decreaser_min == 0)
			sub_min =0;

		else if (decreaser_min>9)
			sub_min =9, decreaser_min -=sub_min;

		else if (decreaser_min<=9)
			sub_min = decreaser_min, decreaser_min =0;
		
		// for calc max
		int sub_max;

		if (decreaser_max == 0)
			sub_max =0;
		else if (decreaser_max>9)
			sub_max =9, decreaser_max -=sub_max;
		else if (decreaser_max<=9)
			sub_max = decreaser_max, decreaser_max =0;

		ans_max += to_string(9-sub_max);
		
		location++;
	}
 
	reverse(ans_max.begin(), ans_max.end());

	cout << ans_min << " " << ans_max << endl;
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int m, s;
	cin >> m >> s;

	answer(m,s);
}
