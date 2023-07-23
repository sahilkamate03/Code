class Solution {
public:
    void solve(string &ans,vector<int> &arr, int n, int k)
    {
        if (n == 0)
            return;

        int f =1;
        for (int i=2; i<n; i++)
            f *=i;

        int i =k/f;
        ans += to_string(arr[i]+1);
        arr.erase(arr.begin()+i, arr.begin()+i+1);
        solve(ans, arr, n-1, k%f);
    }

    string getPermutation(int n, int k) {
        string ans;
        vector<int> arr;
        for (int i=0; i<n; i++)
            arr.push_back(i);
        solve (ans, arr, n, k-1);
        return ans;
    }
};

