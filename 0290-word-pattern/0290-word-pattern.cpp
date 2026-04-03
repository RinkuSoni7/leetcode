class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char ,string>mp1;
        unordered_map<string ,char>mp2;

        vector<string>words;

        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }

        if(pattern.length() != words.size()) return false;

        for(int i=0; i<pattern.size(); i++){
            char ch=pattern[i];
            string word=words[i];

            if(mp1.find(ch)!=mp1.end() && mp1[ch]!=word || mp2.find(word)!=mp2.end() && 
            mp2[word]!=ch){
                return false;
            }
             else{
            mp1[ch]=word;
            mp2[word]=ch;
            
        }
        }

        return true;


        
    }
};