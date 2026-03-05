class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=nums[0];

        for(int i : nums){
            sum=sum+i;
            ans=max(ans,sum);

            if(sum < 0) sum =0;
        }

        return ans;
    }
};