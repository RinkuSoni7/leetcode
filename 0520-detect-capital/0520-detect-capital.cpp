class Solution {
public:
    bool detectCapitalUse(string word) {
        int countcapitals=0;

        for(char&ch : word){
            if(isupper(ch)){
                countcapitals++;
            }
        }

        if(countcapitals==0 || countcapitals==word.length() || countcapitals==1 && isupper(word[0])){
            return true;
        }

        return false;


    }
};