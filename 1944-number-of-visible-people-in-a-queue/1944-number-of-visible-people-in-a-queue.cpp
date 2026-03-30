class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int m = heights.size();
        vector<int> ans(m, 0);
        stack<int> st; 
        
        for(int i = m - 1; i >= 0; i--) {
            int count=0;
            
            
            
            while(!st.empty() && st.top() < heights[i]) {
                st.pop();
                count++;
            }
            
            
            if(!st.empty()){
                count++;
            }
            
            
            ans[i] = count;
            st.push(heights[i]);
        }
        
        return ans;
    }
};