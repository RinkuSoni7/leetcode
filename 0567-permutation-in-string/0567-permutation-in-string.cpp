class Solution {
public:
bool allzero(vector<int>&freq1){
    for(int i : freq1){
        if(i!=0){
            return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();

        vector<int>freq1(26,0);
        // vector<int>freq2(26,0);

        for(char &ch : s1){
            freq1[ch-'a']++;
        }

        int i=0,j=0;

        bool flag=0;

        while(j<m){
            freq1[s2[j]-'a']--;

            while(j-i+1==n){
                if(allzero(freq1)){
                    flag=1;
                    break;
                }

                freq1[s2[i]-'a']++;
                i++;


               
            }


            if(flag==1){
                return true;
            }
            j++;
        }

        return false;
        
    }
};