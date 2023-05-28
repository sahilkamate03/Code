#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
	if (s.size() == 0)
		return 0;
	int bucket[256] = {};
	int ans = 0;
	int front = 0 , tail = 0;
	while (tail < s.size()) {
		front = max(bucket[s[tail]], front);
		bucket[s[tail]] = tail + 1;
		++tail;
		ans = max(ans , tail - front);
	}
	return ans;
}

int main()
{
	cout << lengthOfLongestSubstring("abcabcbb") << endl;
	return 0;
}