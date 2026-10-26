class Solution {
public:

bool check(string s,int S,int e, vector<vector<int>>&dp){
    if(S>=e){
        return true;
    }

    if(dp[S][e]!=-1){
        return dp[S][e];
    }

    if(s[S]==s[e]){
        return dp[S][e]=check(s,S+1,e-1,dp);
    }

    return dp[S][e]=false;

}
    int countSubstrings(string s) {
        int n=s.length();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        int count=0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s,i,j,dp)){
                    count++;
                }
            }
        }
        return count;
    }
};