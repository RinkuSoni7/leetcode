class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();

        unordered_map<char,int>mp;
        for(char&ch : t){
            mp[ch]++;
        }

        int i=0,j=0,ans=INT_MAX;
        int count=t.size();
        // int count=0;
        int start=0;

        while(j<n){

            if(mp[s[j]]>0){
                count--;
            }

            mp[s[j]]--;

            while(count==0){
                if(j-i+1 <ans){
                    ans=j-i+1;
                    start=i;
                }

                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count++;
                }
                i++;
            }
            j++;
        }
            
        if(ans==INT_MAX){
            return "";
        }

        return s.substr(start,ans);
    }
};