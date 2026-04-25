class Solution {
public:
bool ispalindrome(string &s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++,r--;
    }
    return true;
}
void solve(string s,int idx,vector<vector<string>>&ans,vector<string>curr){
    if(idx==s.length()){
        ans.push_back(curr);
    }

    for(int i=idx; i<s.length(); i++){
        if(ispalindrome(s,idx,i)){
            curr.push_back(s.substr(idx,i-idx+1));
            solve(s,i+1,ans,curr);
            curr.pop_back();

        }
    }
}

    vector<vector<string>> partition(string s) {
        

        vector<vector<string>>ans;
        vector<string>curr;

        solve(s,0,ans,curr);
        return ans;
        
    }
};