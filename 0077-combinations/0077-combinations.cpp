class Solution {
public:
        
void solve(int start,vector<vector<int>>&ans,vector<int>&temp,int &n,int k){
    if(k==0){
        ans.push_back(temp);
        return;
    }

    if(start>n) return;

    temp.push_back(start);
    solve(start+1,ans,temp,n,k-1);
    temp.pop_back();
    solve(start+1,ans,temp,n,k);




}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(1,ans,temp,n,k);
        return ans;
        
    }
};