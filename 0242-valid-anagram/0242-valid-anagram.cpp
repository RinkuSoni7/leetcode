class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        vector<int>freq1(26,0);

        for(char &ch : s){
            freq[ch-'a']++;
        }

        for(char &ch : t){
            freq1[ch-'a']++;
        }

        for(int i=0; i<26; i++){
            if(freq[i]!=freq1[i]){
                return false;
            }
        }

        return true;



    }
};