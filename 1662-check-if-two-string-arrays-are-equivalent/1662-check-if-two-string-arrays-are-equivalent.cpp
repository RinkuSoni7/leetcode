class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();

        int w1i=0,i=0;
        int w2i=0,j=0;

        while(w1i<n && w2i<m){
            if(word1[w1i][i]!=word2[w2i][j]){
                return false;
            }
            i++;
            j++;

            if(i==word1[w1i].size()){
                i=0;
                w1i++;
            }
            if(j==word2[w2i].size()){
                j=0;
                w2i++;
            }
        }

        if(w1i==word1.size() && w2i==word2.size()){
            return true;
        }

        return false;


    }
};