class Solution {
public:
vector<int>getnsl(vector<int>& arr,int n){
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        while(st.top()!=-1 && arr[st.top()]> arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);

    }
    return ans;
}

vector<int>getnsr(vector<int>& arr,int n){
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);

    for(int i=n-1; i>=0; i--){
        while(st.top()!=-1 && arr[st.top()]>= arr[i]){
            st.pop();
        }
        ans[i] = (st.top() == -1) ? n : st.top();
        st.push(i);

    }
    return ans;
}





    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsl=getnsl(arr,n);
        vector<int>nsr=getnsr(arr,n);
        int M=1e9+7;

        long long sum=0;

        for(int i=0; i<n; i++){
            long long ls =i- nsl[i];
            long long rs =nsr[i]-i;

            long long totalways=ls*rs;

            long long totalsum=(arr[i]*totalways)%M;

            sum=(sum+totalsum)%M;

        }
        return sum;



    }
};