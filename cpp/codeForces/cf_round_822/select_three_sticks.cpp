#include <bits/stdc++.h>
using namespace std;

int main(){
	int times =0;
	cin >>times;
	while(times--){
	int size_v =0;
	cin >> size_v;
	vector<int> v;
	long long temp =0;
	for (int i=0; i<size_v; i++){
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());

	vector<int> diff;
	for (int i = 0; i<v.size() -1; i++){
		diff.push_back(v[i+1] - v[i]);
	}

	long long min_sum = diff[0] + diff[1];
	int x =0;
	long long add = 0;

	for(int i =1; i<diff.size() - 1; i++){
		add = diff[i] + diff[i+1];
		if (min_sum > add){
			min_sum = add;
			x = i;
		}
	}

	int count = (v[x+1]-v[x]) + (v[x+2]-v[x+1]);
	cout << count << endl;
	
	}
}
