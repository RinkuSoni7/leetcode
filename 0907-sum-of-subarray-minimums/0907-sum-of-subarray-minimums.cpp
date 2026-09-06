class Solution {
public:
vector<int>prevsmaller(vector<int>&arr,int n){
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        while(st.top()!=-1 && arr[st.top()]>= arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

vector<int>nextsmaller(vector<int>&arr,int n){
    stack<int>st;
    // st.push(-1);
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]> arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=n;
        }else{
            ans[i]=st.top();
        }
        
        st.push(i);
    }
    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>prev=prevsmaller(arr,n);
        vector<int>next=nextsmaller(arr,n);

        int M=1e9+7;

        long long sum=0;
        for(int i=0; i<n; i++){
            long long ls=i-prev[i];
            long long rs=next[i]-i;

            long long total=ls*rs;

            long long totalsum=(arr[i]*total)%M;



            sum=(sum+totalsum)%M;


        }
        return sum;

    }
};