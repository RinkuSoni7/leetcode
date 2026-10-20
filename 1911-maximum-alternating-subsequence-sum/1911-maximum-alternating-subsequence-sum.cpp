class Solution {
public:
typedef long long ll;
ll solve(vector<int>& nums,int n,int idx,bool flag,vector<vector<long long>>&dp){
    if(idx>=n) return 0;

    if(dp[idx][flag]!=-1){
        return dp[idx][flag];
    }

     ll skip=solve(nums,n,idx+1,flag,dp);

    ll val=nums[idx];
    if(flag==false){
        val=-val;
    }

    ll take=val+solve(nums,n,idx+1,!flag,dp);

    return dp[idx][flag]=max(skip,take);


}
    long long maxAlternatingSum(vector<int>& nums) {

        int n=nums.size();

        vector<vector<long long >>dp(n,vector<long long >(2,-1));

        return solve(nums,n,0,true,dp);
        
    }
};