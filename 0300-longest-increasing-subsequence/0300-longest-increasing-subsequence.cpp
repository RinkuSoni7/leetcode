class Solution {
public:
int solve(vector<int>& nums,int n,int prev,int curr, vector<vector<int>>&dp){
    if(curr>=n) return 0;

    if(dp[prev+1][curr]!=-1){
        return dp[prev+1][curr];
    }

    int take=0;
    if(prev==-1 || nums[curr]>nums[prev]){
        take=1+solve(nums,n,curr,curr+1,dp);
    }

    int notake=solve(nums,n,prev,curr+1,dp);

    return dp[prev+1][curr]=max(take,notake);
}
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));

        return solve(nums,n,-1,0,dp);
    }
};