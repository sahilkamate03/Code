class Solution {
public:
    int trap(vector<int>& height) {

        int size =height.size();
        vector<int> prefix_max ={0};
        vector<int> suffix_max ={0};

        int temp =0;
        for (int i=0; i<size; i++)
        {
            if (temp<height[i])
                temp =height[i];

            prefix_max[i] =temp;
        }

        temp =0;
        for (int i=size-1; i>=0; i--)
        {
            if (temp<height[i])
                temp =height[i];

            suffix_max[i] =temp;
        }

        int ans =0;
        for (int i=0; i<size; i++)
        {
            ans += min(suffix_max[i], prefix_max[i]) -height[i];
        }       

        return ans;
    }
};
