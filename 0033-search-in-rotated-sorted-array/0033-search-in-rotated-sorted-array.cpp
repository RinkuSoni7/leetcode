class Solution {
public:

int getpivot(vector<int>& nums,int n){
    int s=0,e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(nums[mid]>=nums[0]){
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
            return mid;
        }else if(nums[mid]>k){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}


    int search(vector<int>& nums, int target) {

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