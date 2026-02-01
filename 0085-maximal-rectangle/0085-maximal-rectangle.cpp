class Solution {
    private:
       vector<int> nextsmaller(vector<int> &arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevsmaller(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &arr) {
        int n=arr.size();

        vector<int> next = nextsmaller(arr, n);
        vector<int> prev = prevsmaller(arr, n);

        int area = 0;

        for (int i = 0; i < n; i++) {
            int height = arr[i];

            if (next[i] == -1) {
                next[i] = n;
            }

            int width = next[i] - prev[i] - 1;
            int newArea = height * width;

            area = max(area, newArea);
        }

        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int col = matrix[0].size();

        vector<int> heights(col, 0);
        int area = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            area = max(area,
                       largestRectangleArea(heights));
        }

        return area;
    }
    
};