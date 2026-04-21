class Solution {
public:
int solve(vector<vector<int>>& grid,int n,int m,int d,int r,vector<vector<int>> &dp){
    if(d==n-1 && r==m-1){
        return grid[d][r];
    }
    if(dp[d][r]!=-1){
        return dp[d][r];
    }

if(d==n-1){
    return dp[d][r]= grid[d][r]+solve(grid,n,m,d,r+1,dp);
}else if(r==m-1){
    return dp[d][r]= grid[d][r]+solve(grid,n,m,d+1,r,dp);
}else{
    return dp[d][r]=grid[d][r]+min(solve(grid,n,m,d+1,r,dp),solve(grid,n,m,d,r+1,dp));
}




}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(grid,n,m,0,0,dp);
    }
};