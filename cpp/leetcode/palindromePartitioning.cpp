class Solution {
public:
    bool isPalindrome(string s, int left, int right)
    {
        while (left<right)
        {
            if (s[left++]!=s[right--])
                return false;
        }
        return true;
    }

    void recursion(string s, vector<string> &ans, vector<string> &temp,int N, int index)
    {
        if (index == N)
        {
            ans.push_back(temp);
            return;
        }

        for (int i=index; i<N;i++)
        {
            if (isPalindrome(s, index, i))
            {
                temp.push_back(s.substr(index, i));
                recursion(s, ans, temp, N, index+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recursion(s, ans, temp, s.size(), 0);
        return ans;
    }
};
