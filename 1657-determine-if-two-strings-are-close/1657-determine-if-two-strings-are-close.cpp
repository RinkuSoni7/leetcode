class Solution {
public:
    bool closeStrings(string word1, string word2) {

int n=word1.length();


        if(word1.length()!=word2.length()) return false;
        
        vector<int> freq(26);
        vector<int> freq1(26);




        for(int i=0; i<n; i++){
            freq[word1[i]-'a']++;
            freq1[word2[i]-'a']++;

        }

       
// har kisi me freq same honi chahiye
        for(int i=0; i<26; i++){
            if(freq[i]!=0 && freq1[i]!=0) continue;
            if(freq[i]==0 && freq1[i]==0) continue;

            return false;

        }


        sort(begin(freq),end(freq));
        sort(begin(freq1),end(freq1));

        return freq==freq1;


        


        
    }
};