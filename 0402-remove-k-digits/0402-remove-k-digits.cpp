class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for(int i = 0; i < num.size(); i++) {

            while(!st.empty() && st.back() > num[i] && k > 0) {
                st.pop_back();
                k--;
            }

            if(!st.empty() || num[i] != '0') {
                st.push_back(num[i]);
            }
        }

        while(k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // if(st==''){
        //     return '0';
        // }

        // return st;

        // string ans;

        // while(!st.empty()) {
        //     ans += st.top();
        //     st.pop();
        // }

        // reverse(ans.begin(), ans.end());

        return st.empty() ? "0" : st;
    }
};