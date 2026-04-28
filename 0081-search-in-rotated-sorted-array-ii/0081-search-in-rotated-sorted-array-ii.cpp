class Solution {
public:
int getpivot(vector<int>& nums,int n){
    int s=0;
    int e=n-1;

    while(s<e){
        while(s<e && nums[s]==nums[s+1]) s++;
        while(s<e && nums[e]==nums[e-1]) e--;
            

        int mid=s+(e-s)/2;

        if(nums[mid]>nums[e]){
            s=mid+1;
        }else{
            e=mid;
        }
    }
    return s;
}

int binary(vector<int>& nums,int s,int e,int k){
    while(s<=e){
        int mid=s+(e-s)/2;

        if(nums[mid]==k){
            return true;
        }else if(nums[mid]>k){
            e=mid-1;
        }else{
            s=mid+1;
        }

    }
    return false;
}
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int k=target;
        int pivot=getpivot(nums,n);

        if(k>=nums[pivot] && k<=nums[n-1]){
            return binary(nums,pivot,n-1,k);
        }else{
            return binary(nums,0,pivot-1,k);
        }
    }
};