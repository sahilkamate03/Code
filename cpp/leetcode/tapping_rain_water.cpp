class Solution {
public:
    int trap(vector<int>& height) {
        height.push_back(0);
        
        int dec_pt =height[0];
        int dec_pt_index =0;

        int ans =0;
        int temp =0;
        int dip =1;
        for (int i=0; i<height.size()-1; i++)
        {
            int diff =dec_pt -height[i];

            if (diff > 0)
            {
                temp += diff;
            }

            if (!dip && height[i] < height[i+1])
            {
                dip =1;
            }

            if (dip && height[i] > height[i+1])
            {
                if (diff > 0)
                {
                    int len =i -dec_pt_index;
                    temp -=(diff * len);
                }
                ans +=temp;
                dec_pt =height[i];
                temp =0;     
                dip =0;
            }

          }

        return ans;
    }
};
