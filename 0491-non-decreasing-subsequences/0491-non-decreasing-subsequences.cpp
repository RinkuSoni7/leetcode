class Solution {
public:
void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&curr,int index){
    
        if(curr.size()>=2){
            ans.push_back(curr);
            
        }

        unordered_set<int>st;

        for(int i=index; i<nums.size(); i++){
            if((curr.empty() || nums[i]>=curr.back()) && (st.find(nums[i])==st.end())){
                curr.push_back(nums[i]);
              solve(nums,ans,curr,i+1);
              curr.pop_back();
              st.insert(nums[i]);

            }
        }



   
}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // int n=nums.size();

        vector<vector<int>>ans;
        vector<int>curr;

        int index=0;

        solve(nums,ans,curr,index);

        return ans;


    }
};