class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(m==0) return 0;
        for(int i=0; i<=n-m; i++){
            string t=haystack.substr(i,m);
            if(t==needle){
                return i;
            }
        }
        return -1;
    }
};