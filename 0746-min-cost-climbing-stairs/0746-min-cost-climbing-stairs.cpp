class Solution {
public:
int solve(vector<int>& cost,int n,int index, vector<int> &dp){
    if(index>=n) return 0;
    if(dp[index]!=-1){
        return dp[index];
    }


    int a=cost[index]+solve(cost,n,index+1,dp);
    int b=cost[index]+solve(cost,n,index+2,dp);

    return dp[index]=min(a,b);

    
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);

        return min(solve(cost,n,0,dp),solve(cost,n,1,dp));
        
    }
};