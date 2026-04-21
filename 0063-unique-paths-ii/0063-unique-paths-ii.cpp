class Solution {
public:
vector<vector<int>>directions={{0+1,0},{0,0+1}};
int solve(vector<vector<int>>& obstacleGrid,int n,int m,int x,int y,vector<vector<int>>&dp){
    if(x<0 || x>=n || y<0 || y>= m || obstacleGrid[x][y]==1) return 0;

    if(x==n-1 && y==m-1){
        return 1 ;
    }

    if(dp[x][y]!=-1){
        return dp[x][y];
    }

   int ans=0;

    for(vector<int>dir : directions){
        int newx=x+dir[0];
        int newy=y+dir[1];

        ans+=solve(obstacleGrid,n,m,newx,newy,dp);

    }

    return dp[x][y]=ans;

    





}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

         return solve(obstacleGrid,n,m,0,0,dp);

        
    }
};