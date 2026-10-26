class Solution {
public:
bool palindrome(string s,int i,int j){
    if(i>=j) return true;

    if(s[i]==s[j]){
        return palindrome(s,i+1,j-1);
    }

    return false;
}
void solve(string s,vector<vector<string>>&result, vector<string>curr,int idx){
    if(idx==s.length()){
        result.push_back(curr);

        return;
    }

    for(int i=idx; i<s.length(); i++){
        if(palindrome(s,idx,i)){
            curr.push_back(s.substr(idx,i-idx+1));
            solve(s,result,curr,i+1);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n=s.length();

        vector<vector<string>>result;
        vector<string>curr;

        solve(s,result,curr,0);

        return result;

        
        
    }
};