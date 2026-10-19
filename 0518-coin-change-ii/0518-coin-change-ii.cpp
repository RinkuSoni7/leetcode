class Solution {
public:
int solve(int amount, vector<int>& coins,int n, vector<vector<int>>&dp,int idx){
    if(amount==0) return 1;

    if(idx==n) return 0;

    if(dp[idx][amount]!=-1){
        return dp[idx][amount];
    }

    if(coins[idx]>amount){
        return solve(amount,coins,n,dp,idx+1);
    }

    

    dp[idx][amount]=solve(amount-coins[idx],coins,n,dp,idx)+solve(amount,coins,n,dp,idx+1);

    return dp[idx][amount];
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

       return solve(amount,coins,n,dp,0);
        
    }
};