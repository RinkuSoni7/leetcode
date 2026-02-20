class Solution {
public:
int n;
vector<int>dp;
unordered_set<string>st;
bool solve(int idx,string &s){

    if(idx==n){
        return true;
    }

    if (dp[idx] != -1)
            return dp[idx];


    // if(st.find(s)!=st.end()){
    //     return true;
    // }



    for(int i=1; i<=n; i++){
        string temp=s.substr(idx,i);

        if(st.find(temp)!=st.end() && solve(idx+i,s)){
            return dp[idx]=1;
        }
    }
    return dp[idx]=0;
}

    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();

        dp.assign(n,-1);

        for(string &word : wordDict){
            st.insert(word);
        }

        return solve(0,s);
    }
};