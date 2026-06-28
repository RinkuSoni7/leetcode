class Solution {
public:
vector<vector<int>>ans;

void twosum(vector<int>& nums,int target,int s,int e){
    while(s<e){
        if(nums[s]+nums[e]>target){
            e--;
        }
        else  if(nums[s]+nums[e]<target){
            s++;
        }
        else{
            ans.push_back({-target,nums[s],nums[e]});
            s++;
            e--;


            while(s<e && nums[s]==nums[s-1]) s++;
            while(s<e && nums[e]==nums[e+1]) e--;
            

        }
        
    }
    
}
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return {};


        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]){

                continue;
            }
                int n1=nums[i];
                int target=-n1;

                twosum(nums,target,i+1,n-1);
            }
        
        return ans;
        
    }
};