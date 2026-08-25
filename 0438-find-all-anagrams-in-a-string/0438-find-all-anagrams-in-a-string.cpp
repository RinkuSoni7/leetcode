class Solution {
public:
bool allzeros(unordered_map<char,int>&mp){
    for(auto i:mp){
        if(i.second!=0) return false;
    }
    return true;

}
    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(auto& i : p){
            mp[i]++;
        }

        vector<int>result;
        int i=0,j=0;
        int k=p.size();



        while(j<n){
            mp[s[j]]--;

            if(j-i+1==k){
                if(allzeros(mp)){
                    result.push_back(i);
                }

                mp[s[i]]++;
                i++;

            

            }

            j++;

        }
        return result;
    }
};