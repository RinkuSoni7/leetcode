/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
 int binary(MountainArray &mountainArr,int s,int e,int target){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mountainArr.get(mid)==target){
            return mid;
        }else if(mountainArr.get(mid)<target){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return -1;
 }

int reversebinary(MountainArray &mountainArr,int s,int e,int target){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mountainArr.get(mid)==target){
            return mid;
        }else if(mountainArr.get(mid)<target){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
 }

 int peakindex(MountainArray &mountainArr){
    int n=mountainArr.length();
    int s=0,e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(mountainArr.get(mid)<mountainArr.get(mid+1)){
            s=mid+1;
        }else{
            e=mid;
        }
    }
    return s;
 }

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

    int n=mountainArr.length();
        
        int idx=peakindex(mountainArr);

        int result=binary(mountainArr,0,idx,target);
        if(result!=-1){
            return result;
        }


        int result1=reversebinary(mountainArr,idx+1,n-1,target);

        return result1;

        








    }
};