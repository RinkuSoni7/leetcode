class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string S="";
        string T="";

        for(string s: word1){
            S+=s;
        }

        for(string t : word2){
            T+=t;
        }

        return S==T;

    }
};