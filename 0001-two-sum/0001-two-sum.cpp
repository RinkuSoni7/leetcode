class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;

        for(int i=0; i<nums.size(); i++){
            int element=target-nums[i];
            if(mp.find(element)!=mp.end()){
                return{mp[element],i};
            }
            mp[nums[i]]=i;
        }
        return{};
    }
};