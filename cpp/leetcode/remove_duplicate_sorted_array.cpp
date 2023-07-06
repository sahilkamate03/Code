#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1) return 0;
        
        int ans =0;
        int i=1; int j=1;
        for (; i<nums.size() && j<nums.size(); i++)
        {
            if (nums[i-1] >= nums[i])
            {
                ans++;
                while(j<nums.size() && nums[j]<=nums[i])
                    j++:

                nums[i] =nums[j];
                if (nums[j]==nums[nums.size()-1])
            }
        }

        return ans;
    }
};

int main()
{
	Solution s;
	vector<int> nums ={1,1,2};
	s.removeDuplicates(nums);
}
