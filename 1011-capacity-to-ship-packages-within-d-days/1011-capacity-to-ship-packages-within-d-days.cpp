class Solution {
public:
bool ispossible(vector<int>& weights, int days,int n,int mid){
    int count=1;
    int weight=0;

    for(int i=0; i<n; i++){
        if(weight+weights[i]<=mid){
            weight+=weights[i];
        }else{
            count++;
            if(count> days || weights[i]>mid) return false;
            weight=weights[i];

        }
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=weights[i];
        }
        int e=sum;
        int s=*max_element(weights.begin(),weights.end());

        int ans=-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(weights,days,n,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};