#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[9];

	for (int i=0; i<9; i++) cin >> arr[i];

	int n;
	int ans =28, result;
	int min_no, max_no, sum;
	min_no = min(min(arr[0]+arr[8],arr[2]+arr[6]), min(arr[1]+arr[7], arr[3]+arr[5]));
	max_no = max(max(arr[0]+arr[8],arr[2]+arr[6]), max(arr[1]+arr[7], arr[3]+arr[5]));
	int middle_no = arr[4];

	for (int j=min(min_no+middle_no, middle_no*3); j<=max_no+middle_no; j++){
		result =0; n=0;
		for (int i=0; i<4; i++){
			if (arr[n]+arr[8-n] != j - middle_no){
				if (arr[n] > arr[8-n]) result+= abs((j - (arr[8-n] +middle_no)) -arr[n]);
				else result+= abs(arr[8-n] -(j - (arr[n] +middle_no)));
			}
			n++;
		}
		cout << ans << " " << j << endl;
		ans = min(ans,result);

	}

	cout << ans << endl;
}
                                                              