class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        int sum=0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    sum=nums[i]+nums[j]+nums[k];

                    if(abs(sum-target)<abs(ans-target)){
                        ans=sum;
                    }
                }
            }
        }
return ans;
       

    }

};