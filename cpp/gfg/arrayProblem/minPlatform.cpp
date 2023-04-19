	#include <bits/stdc++.h>
	using namespace std;

	int main()
	{
		std::vector<int> v;
		v ={1,2,3,4,5};
		auto maxElement =max_element(v.begin(), v.end());
		auto minElement =min_element(v.begin(), v.end());

		cout << *maxElement << endl;
		cout << *minElement << endl;
		return 0;
	}