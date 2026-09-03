class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefix=0,count=0,rem=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0; i<n; i++){
            prefix+=nums[i];
            rem=prefix % k;
            if(rem<0){
                rem=rem+k;
            }
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
                mp[rem]++;
            }else{
                mp[rem]=1;
            }

        }
        return count;
    }
};