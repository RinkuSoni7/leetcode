class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n=nums.size();

        sort(nums.begin(),nums.end());

        int count=1,maxi=0;
        int smaller=INT_MIN;

        for(int i=0; i<n; i++){
            if(nums[i]-1==smaller){
                count++;
                smaller=nums[i];
            }else if(nums[i]!=smaller){
                count=1;
                smaller=nums[i];
            }
            maxi=max(count,maxi);
        }

        return maxi;
        
    }
};