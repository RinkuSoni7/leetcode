class Solution {
public:
int solve(int amount,int n ,vector<int>& coins,int i, vector<vector<int>>&dp){
    if(amount==0) return 1;
    if(i>= n|| amount<0) return 0;

    if(dp[i][amount]!=-1){
        return dp[i][amount];

    }

    dp[i][amount]=solve(amount-coins[i],n,coins,i,dp)+solve(amount,n,coins,i+1,dp);

    return dp[i][amount];
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(amount,n,coins,0,dp);
    }
};