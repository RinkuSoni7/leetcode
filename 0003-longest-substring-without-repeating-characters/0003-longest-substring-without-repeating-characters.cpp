class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        
        int i = 0, j = 0;
        int maxlength = 0;

        while(j < s.length()){
            
            mp[s[j]]++;

            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }

            maxlength = max(maxlength, j - i + 1);

            j++;
        }

        return maxlength;
    }
};