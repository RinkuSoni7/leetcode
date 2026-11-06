class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i : nums){
            mp[i]++;
        }

        int ans=-1;

        for(int i=0; i<=nums.size(); i++){
            if(mp[i]==0){
                ans=i;
            }
        }

        return ans;
    }
};