class Solution {
public:
int solve(vector<int>& nums,int n,int i,vector<int>&dp)
{
    if(i>=n){
        return 0;
    }

    if(dp[i]!=-1){
        return dp[i];
    }

    int a=nums[i]+solve(nums,n,i+2,dp);
    int b=0+solve(nums,n,i+1,dp);

    return dp[i]=max(a,b);




}
    int rob(vector<int>& nums) {
        int n=nums.size();

         if (n == 1) {
            return nums[0];
        }

        vector<int>dp(n+1,-1);
        int ans=solve(nums,n-1,0,dp);

        vector<int>dp1(n+1,-1);

        int ans1=solve(nums,n,1,dp1);

        return max(ans,ans1);
        
    }
};