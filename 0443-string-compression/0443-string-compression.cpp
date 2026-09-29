class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        vector<pair<char,int>>result;
        int i=0;
        while(i<n){
            char ch=chars[i];
            int count=0;
            while(i<n && chars[i]==ch){
                i++;
                count++;
            }
            result.push_back({ch,count});
        }
        int index=0;
        for(auto&it : result){
            chars[index++]=it.first;

            if(it.second>1){
                    string num=to_string(it.second);
                

                for(auto&ch :num){
                    chars[index++]=ch;
                }
        }
        }

        return index;
    }
};