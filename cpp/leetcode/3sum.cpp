#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int i=0;
        while (i < nums.size()-2)
        {
            while(i!=0 && nums[i]!=nums[i+1]) i++;
            cout << i << " " << nums[i] << endl;
            int j =i+1;
            int k=nums.size() -1;

            while (j<k)
            {
                int sum =nums[i]+nums[j]+nums[k];
                cout << sum << endl;
                if (sum == 0) {
                    cout << nums[i] << " " << nums[j] << " "  << nums[k] << endl;
                    ans.push_back({nums[i]+nums[j]+nums[k]});
                    j++; k--;
                }
                else if (sum<0) j++;
                else k--;
                while (j<k && nums[j]==nums[j+1]){ j++;}
                while (j<k && nums[k-1]==nums[k]){ k--;}
            }
            i++;
        }

        return ans;
    }
};

int main() {
  vector < int > arr{-1,0,1,2,-1,-4};
  vector < vector < int >> ans;
  Solution s;
  ans = s.threeSum(arr);
  cout << "The triplets are as follows: "<< endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] <<" ";
    }
    cout << endl;
  }
  return 0;
}
