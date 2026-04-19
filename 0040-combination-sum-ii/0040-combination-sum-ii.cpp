class Solution {
public:
void solve(vector<int>& candidates, int target,int n,vector<vector<int>>&ans, vector<int>temp,int index){
    if(target==0){
        ans.push_back(temp);
        return;
    }

    if(target<0 || index>=n) return;

    for(int i=index; i<n; i++){
        if(i>index && candidates[i]==candidates[i-1]){
            continue;
        }

        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],n,ans,temp,i+1);
        temp.pop_back();


    }

    
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;

        solve(candidates,target,n,ans,temp,0);
        return ans;
        

        
    }
};