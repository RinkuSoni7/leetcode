class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int n=num.size();
        for(int i=0; i<n; i++){
            while(!ans.empty() && k>0 && ans.back() > num[i] ){
                ans.pop_back();
                k--;
            }
            if(!ans.empty() || num[i]!='0'){
                ans.push_back(num[i]);
            }

        }

        while(!ans.empty() && k>0){
            ans.pop_back();
            k--;
        }

        return ans.empty() ? "0" : ans;

        
        
    }
};