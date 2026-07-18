class Solution {
public:
vector<int>prevsmaller(vector<int>& arr,int n){
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

vector<int>nextsmaller(vector<int>& arr,int n){
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);

    for(int i=n-1; i>=0; i--){
        while(st.top()!=-1 && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}



    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int>prev=prevsmaller(heights,n);
            vector<int>next=nextsmaller(heights,n);


        int area=0;
        int ans=0;
        for(int i=0; i<n; i++){

            
            int h=heights[i];

            if(next[i]==-1){
                next[i]=n;

            }

            int width=next[i]-prev[i]-1;

            int newarea=width*h;

            area=max(area,newarea);
        }
        return area;
    }
};