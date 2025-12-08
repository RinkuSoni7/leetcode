class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int totalSum = INT_MIN;
        for(int i:nums)
        {
            sum = sum + i;
            totalSum = max(totalSum , sum);
            if(sum < 0) sum = 0;

        }
        return totalSum;
    }
};