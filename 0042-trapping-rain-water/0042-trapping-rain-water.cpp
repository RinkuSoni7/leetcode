class Solution {
public:

    vector<int> getlmax(vector<int>& height, int n) {

        vector<int> ans(n);

        ans[0] = height[0];

        for(int i = 1; i < n; i++) {
            ans[i] = max(ans[i-1], height[i]);
        }

        return ans;
    }


    vector<int> getrmax(vector<int>& height, int n) {

        vector<int> ans(n);

        ans[n-1] = height[n-1];

        for(int i = n-2; i >= 0; i--) {
            ans[i] = max(ans[i+1], height[i]);
        }

        return ans;
    }


    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> lmax = getlmax(height, n);
        vector<int> rmax = getrmax(height, n);

        int sum = 0;

        for(int i = 0; i < n; i++) {

            int h = min(lmax[i], rmax[i]) - height[i];

            sum += h;
        }

        return sum;
    }
};