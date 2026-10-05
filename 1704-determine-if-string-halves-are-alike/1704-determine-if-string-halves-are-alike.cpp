class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        string t=s.substr(0,n/2);

        int count=0,count1=0;

        for(char &ch : t){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
            ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                count++;
            }
        }

         for(int i=n/2; i<s.length(); i++){
            char ch=s[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
            ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                count1++;
            }
        }

        return count==count1;






    }
};