#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int year;
	cin >> year;
	string Year = to_string(year);

	if (year==1918) cout << "26.09." + Year << endl;

	else if (year<1919){
		if (year%4==0) cout<< "12.09." + Year << endl;
		else cout << "13.09." + Year << endl;
	}

	else if (year > 1918) {
		if (year%400==0 || (year%4==0 && year%100!=0)) cout<< "12.09." + Year << endl;
		else cout << "13.09." + Year << endl;
	}

}
