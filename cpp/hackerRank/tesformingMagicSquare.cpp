#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	// combination initializer
	int c1[9] ={4,9,2,7,6,1,8,3,5};//
	int c2[9] ={8,1,6,7,2,9,4,3,5};//
	int c3[9] ={2,9,4,3,8,1,6,7,5};//
	int c4[9] ={6,1,8,3,4,9,2,7,5};//

	int c5[9] ={8,3,4,9,2,7,6,1,5};//
	int c6[9] ={4,3,8,1,6,7,2,9,5};//
	int c7[9] ={6,7,2,9,4,3,8,1,5};//
	int c8[9] ={2,7,6,1,8,3,4,9,5};//


	int ans=100;
	int arr[9]={};
	cin >>arr[0] >>arr[1] >>arr[2] >>arr[7] >>arr[8] >>arr[3] >>arr[6] >>arr[5] >>arr[4];

	int c[72];
	int n=0;

	// combination maker in one array
	for (int i=0;i<9;i++) c[n++]=c1[i];
	for (int i=0;i<9;i++) c[n++]=c2[i];
	for (int i=0;i<9;i++) c[n++]=c3[i];
	for (int i=0;i<9;i++) c[n++]=c4[i];

	for (int i=0;i<9;i++) c[n++]=c5[i];
	for (int i=0;i<9;i++) c[n++]=c6[i];
	for (int i=0;i<9;i++) c[n++]=c7[i];
	for (int i=0;i<9;i++) c[n++]=c8[i];

	// for (int i=0; i<72; i++) {cout << c[i] << " "; }
	int sum=0, j=0;
	for (int i=0; i<72; i++){
		if (i!=0 && i%9==0) ans=min(sum,ans) ,j=0, sum=0;
		sum +=abs(arr[j++]-c[i]);
	}
	ans = min(sum,ans);

	cout << ans;
	
}
