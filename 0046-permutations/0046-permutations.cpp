class Solution {
public:

void solve(vector<int>& nums, vector<vector<int>> &ans,int index){

    if(index>=nums.size()){
        ans.push_back(nums);
    }


    for(int j=index; j<nums.size(); j++){
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[j]);

    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        // vector<int>temp;
        int index=0;


        solve(nums,ans,index);
        return ans;
    }
};