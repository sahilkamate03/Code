#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[9];

	for (int i=0; i<9; i++) cin >> arr[i];

	int n =0;
	int result = 0;
	int middle_no = 5;
	for (int i=0; i<4; i++){
		if (arr[n]+arr[8-n] != middle_no*3 - middle_no){
			if (arr[n] > arr[8-n]) result+= abs((middle_no *3 - (arr[8-n] +middle_no)) -arr[n]);
			else result+= abs(arr[8-n] -(middle_no *3 - (arr[n] +middle_no)));
		}
		n++;
	}

	cout << result << endl;
}
                                                              