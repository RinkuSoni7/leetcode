class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int golaindex=-1;
        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                golaindex=i-1;
                break;
            }
        }

        if(golaindex!=-1){
            int swapindex=golaindex;
        

        for(int j=n-1; j>=0; j--){
            if(nums[j] > nums[golaindex]){
                swapindex=j;
                break;
            }
        }


        swap(nums[golaindex],nums[swapindex]);
        
        

        reverse(nums.begin()+golaindex+1,nums.end());
        }
         else {
            // Already the largest permutation
            reverse(nums.begin(), nums.end());
        }
        
    }
};