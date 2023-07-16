//class implemented
/*
   struct Item{
   int value;
   int weight;
   };
   */


class Solution
{
    public:
        //Function to get the maximum total value in the knapsack.

        static bool comparator(Item i1, Item i2)
        {
            return (static_cast<float> (i1.value)/i1.weight > static_cast<float> (i2.value)/i2.weight);
        }

        double fractionalKnapsack(int W, Item arr[], int n)
        {
            // Your code here
            sort(arr, arr+n, comparator);

            double ans =0;
            double weight =0;
            for (int i=0; i<n && weight<W; i++)
            {
                double diff =W-weight;
                if (diff >= arr[i].weight)
                {
                    ans +=arr[i].value;
                    weight +=arr[i].weight;
                }
                else 
                {
                    ans += (diff * arr[i].value) /arr[i].weight;
                    weight +=diff;
                }
            }

            return ans;    
        }
};
