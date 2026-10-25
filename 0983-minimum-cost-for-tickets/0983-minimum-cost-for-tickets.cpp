class Solution {
public:
int solve(vector<int>& days, vector<int>& costs,vector<int>&dp,int idx){
    if(idx>=days.size()) return 0;

    if(dp[idx]!=-1){
        return dp[idx];
    }

    int one=costs[0]+solve(days,costs,dp,idx+1);

    int i;
    for(i=idx; i<days.size() && days[i]<days[idx]+7; i++);

    int sev=costs[1]+solve(days,costs,dp,i);

    for(i=idx; i<days.size() && days[i]<days[idx]+30; i++);

    int thirty=costs[2]+solve(days,costs,dp,i);

    return dp[idx]=min(one,min(sev,thirty));


}
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n=days.size();

        vector<int>dp(n,-1);

        return solve(days,costs,dp,0);
        
    }
};