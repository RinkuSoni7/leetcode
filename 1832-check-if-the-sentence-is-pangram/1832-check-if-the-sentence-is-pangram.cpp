class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>count(26,0);
        int ans=0;
        for(char &ch : sentence){
            int index=ch-'a';
            if(count[index]==0){
                count[index]++;
            ans++;

            }
        }

       if(ans==26){
        return true;
       }

       return false;
    }
};