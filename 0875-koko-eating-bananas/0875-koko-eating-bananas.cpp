class Solution {
public:
bool ispossible(vector<int>& piles, int h,int mid){
    long long actualhour=0;
    for(int i : piles){
        actualhour+=i/mid;

        if(i%mid!=0){
            actualhour++;
        }

        if(actualhour>h) return false;
    }
     return actualhour <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        int ans=-1;

        while(s<=e){

            int mid=s+(e-s)/2;

            if(ispossible(piles,h,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }

        }
        return ans;
    }
};