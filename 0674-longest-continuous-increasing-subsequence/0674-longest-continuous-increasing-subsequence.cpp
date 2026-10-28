class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();

        int count=1,maxi=1;


        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                count++;
            }
                else{
                count=1;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};