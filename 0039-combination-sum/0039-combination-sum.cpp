class Solution {
public:
void solve(vector<int>& candidates, int target,int index,vector<vector<int>>& ans,vector<int>& temp,int n){
    if(target==0){
        ans.push_back(temp);
        return;
    }

    if(index>=n || target<0) return;

    solve(candidates,target,index+1,ans,temp,n);


     temp.push_back(candidates[index]);

    solve(candidates,target-candidates[index],index,ans,temp,n);
    temp.pop_back();


    

}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        int index=0;
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates,target,index,ans,temp,n);
        return ans;
    }
};