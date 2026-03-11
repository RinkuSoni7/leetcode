class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int x : nums){
            mp[x]++;
            if(mp[x]>2){
                return false;
            }
        }

        return true;
        
    }
};