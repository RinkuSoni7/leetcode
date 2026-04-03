class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int start=n-1;
        int length=0;

        while( start >=0 && s[start]==' '){
            start--;
        }



        while(start >=0 && s[start]!=' '){
            length++;
            start--;

        }

        return length;
    }
};