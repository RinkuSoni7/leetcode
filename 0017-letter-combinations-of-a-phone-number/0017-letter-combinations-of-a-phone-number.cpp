class Solution {
public:

void solve(string digits,string mapping[10],vector<string>&ans,string temp,int idx){
    if(idx>=digits.length()){
        ans.push_back(temp);
        return;
    }

    int number=digits[idx]-'0';
    string value=mapping[number];

    for(int i=0; i<value.length(); i++){
        temp.push_back(value[i]);
        solve(digits,mapping,ans,temp,idx+1);
        temp.pop_back();
    }
}

    vector<string> letterCombinations(string digits) {
        int n=digits.size();

        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string>ans;
        string temp="";

        solve(digits,mapping,ans,temp,0);
        return ans;

        
    }
};