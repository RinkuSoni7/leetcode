class Solution {
public:
bool solve(string s, unordered_set<string>st,int idx,vector<int>&dp){
    if(idx==s.length()) return true;

    if(dp[idx]!=-1){
        return dp[idx];
    }

    if(st.find(s)!=st.end()){
        return true;
    }



    for(int i=1; i<=s.length(); i++){
        string temp=s.substr(idx,i);

        if(st.find(temp)!=st.end() && solve(s,st,idx+i,dp)){
            return dp[idx]= true;
        }
    }

    return dp[idx]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string>st;

        vector<int>dp(s.length(),-1);

        for(string& word : wordDict){
            st.insert(word);
        }

        return solve(s,st,0,dp);
        
    }
};