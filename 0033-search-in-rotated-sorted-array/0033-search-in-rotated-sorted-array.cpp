class Solution {
public:
int getpivot(vector<int>& nums, int n){
    int s=0;
    int e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(nums[mid]>=nums[e]){
            s=mid+1;
        }else{
            e=mid;
        }
    }
    return s;
}

int binary(vector<int>& nums,int n, int target,int s,int e){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>target){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=getpivot(nums,n);

        if(target>=nums[pivot] && target<= nums[n-1]){
            return binary(nums,n,target,pivot,n-1);
        }else{
            return binary(nums,n,target,0,pivot-1);
        }
        // return -1;

    }
};