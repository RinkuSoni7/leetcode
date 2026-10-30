class Solution {
public:
vector<int>Lmax(vector<int>height,int n){
    vector<int>ans(n);
    ans[0]=height[0];
    for(int i=1; i<n; i++){
        ans[i]=max(ans[i-1],height[i]);
    }

    return ans;

}

vector<int>Rmax(vector<int>height,int n){
    vector<int>ans1(n);
    ans1[n-1]=height[n-1];
    for(int i=n-2; i>=0; i--){
        ans1[i]=max(height[i],ans1[i+1]);
    }

    return ans1;

}
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>rmax=Rmax(height,n);
        vector<int>lmax=Lmax(height,n);

        int sum=0;

        for(int i=0; i<n; i++){
            int h=min(lmax[i],rmax[i])-height[i];

            sum+=h;
        }
return sum;
        

    }
};