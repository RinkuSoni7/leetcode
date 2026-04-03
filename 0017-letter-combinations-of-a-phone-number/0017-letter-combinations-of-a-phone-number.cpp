class Solution {
public:
void solve(string digits,string temp,vector<string> &ans,int index,string mapping[]){
    if(index>=digits.length()){
        ans.push_back(temp);
        return;
    }
int number=digits[index]-'0';
string value=mapping[number];

for(int i=0; i<value.length(); i++){
    temp.push_back(value[i]);
    solve(digits,temp,ans,index+1,mapping);
    temp.pop_back();

}




}
    vector<string> letterCombinations(string digits) {
        string temp="";
        vector<string>ans;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;

        solve(digits,temp,ans,index,mapping);
        return ans;

    }
};