class Solution {
public:
bool ispossible(vector<int>& nums, int k,int mid,int n){
    long long sum=0;
    int count=1;
    for(int i=0; i<n; i++){
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }else{
            if(count>=k || nums[i]>mid) return false;
            count++;
            sum=nums[i];
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0;
        long long sum=0;
        for(int i : nums){
            sum+=i;
        }

        int e=sum;
        int ans=-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(nums,k,mid,n)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;

    }
};