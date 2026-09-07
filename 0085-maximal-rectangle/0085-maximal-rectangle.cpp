class Solution {
public:

vector<int>prevsm(vector<int> &arr,int n){
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);

    for(int i=0; i<n; i++){
        while(st.top()!=-1 && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

vector<int>nextsm(vector<int> &arr,int n){
    stack<int>st;
    st.push(n);
    vector<int>ans(n);

    for(int i=n-1; i>=0; i--){
        while(st.top()!=n && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}


int largestarea(vector<int> &arr ){
    int n=arr.size();

    vector<int>prev=prevsm(arr,n);
    vector<int>next=nextsm(arr,n);
    int ans=0;

    for(int i=0; i<n; i++){
        int h=arr[i];

        

        int w=next[i]-prev[i]-1;

        int newarea=h*w;

        ans=max(ans,newarea);
    }
    return ans;


}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>height(m,0);
        int area=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    height[j]+=1;
                }else{
                    height[j]=0;
                }
            }
            area=max(area,largestarea(height));
        }
        return area;
    }
};