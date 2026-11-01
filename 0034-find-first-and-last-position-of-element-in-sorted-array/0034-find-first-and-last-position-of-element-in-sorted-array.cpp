class Solution {
public:
int findfirstocc(vector<int>& nums, int target, int n ) {
    int s = 0;
    int e = n-1;
    int left_most =-1;
    int mid = s +(e - s)/2;

    while(s<=e) {
        if(nums[mid]==target) {
            left_most = mid;
            e = mid-1;
        } else if (nums[mid]<target) {
            s= mid + 1;}
             else{
            e = mid -1;
        }
        mid = s + (e - s)/2;
    }
    return left_most;
}

int findlasttocc(vector<int>& nums, int target, int n ) {
    int s = 0;
    int e = n-1;
    int right_most =-1;
    int mid = s +(e - s)/2;

    while(s<=e) {
        if(nums[mid]==target) {
            right_most = mid;
            s = mid+1;
            } else if (nums[mid]<target) {
                s= mid + 1;
            }
            else{
            e = mid -1;
        }
        mid = s + (e - s)/2;
    }
    return right_most;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left_most = findfirstocc(nums,target,n);
        int right_most = findlasttocc(nums,target,n);
        return {left_most,right_most};
        
    }
};