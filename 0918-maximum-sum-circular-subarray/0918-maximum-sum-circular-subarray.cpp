class Solution {
public:
int kadanemax(vector<int>& nums,int n){
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        sum+=nums[i];
        maxi=max(maxi,sum);
        if(sum<0) sum=0;
    }
    return maxi;
}

int kadanemin(vector<int>& nums,int n){
    int sum=0;
    int mini=INT_MAX;
    for(int i=0; i<n; i++){
        sum+=nums[i];
        mini=min(mini,sum);
        if(sum>0) sum=0;
    }
    return mini;
}

    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }

        int maxsum=kadanemax(nums,n);

        int minsum=kadanemin(nums,n);

        int circularsum=sum-minsum;

        if(maxsum>0){
            return max(maxsum,circularsum);
        }else{
            return maxsum;
        }

        
    }
};