class Solution {
public:
int solve(int amount,vector<int>& coins,int n,int index,vector<vector<int>>&dp){
    if(amount==0) return 1;

     if (index == n || amount < 0) return 0;

      if(dp[index][amount]!=-1){
        return dp[index][amount];
    }


    if(amount < coins[index]){
       return dp[index][amount]= solve(amount,coins,n,index+1,dp);
    }

   

    dp[index][amount]= solve(amount,coins,n,index+1,dp)+solve(amount-coins[index],coins,n,index,dp);
    return dp[index][amount];


}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int index=0;

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(amount,coins,n,index,dp);
        
    }
};