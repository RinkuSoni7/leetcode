class Solution {
public:
int kadansmaxsum(vector<int>& nums,int n){
    int sum=0;
    int ans=INT_MIN;
    for(int i=0; i<n; i++){
        sum+=nums[i];
        ans=max(ans,sum);

        if(sum<0) sum=0;
    }
    return ans;
}


int kadansminsum(vector<int>& nums,int n){
    int sum=0;
    int ans=INT_MAX;
    for(int i=0; i<n; i++){
        sum+=nums[i];
        ans=min(ans,sum);

        if(sum>0) sum=0;
    }
    return ans;
}
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();

        int sum=0;

        for(int i=0; i<n; i++){
            sum+=nums[i];
        }

        int maxisum=kadansmaxsum(nums,n);
        int minisum=kadansminsum(nums,n);

        int circular_sum=sum-minisum;

        if(maxisum>0){
            return max(maxisum,circular_sum);
        }else{
            return maxisum;
        }

        
    }
};