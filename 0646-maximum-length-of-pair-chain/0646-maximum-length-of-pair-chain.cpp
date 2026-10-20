class Solution {
public:
int solve(vector<vector<int>>& pairs,int n,int prev,int curr,vector<vector<int>>&dp){
    if(curr>=n) return 0;

    if(dp[prev+1][curr]!=-1){
        return dp[prev+1][curr];
    }

    int take=0;

    if(prev==-1 || pairs[curr][0] > pairs[prev][1]){
        take=1+solve(pairs,n,curr,curr+1,dp);
    }

       int  notake=solve(pairs,n,prev,curr+1,dp);

       return dp[prev+1][curr]=max(take,notake);



}
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n=pairs.size();

        sort(pairs.begin(),pairs.end());

        vector<vector<int>>dp(n+1,vector<int>(n,-1));

        return solve(pairs,n,-1,0,dp);
    }
};