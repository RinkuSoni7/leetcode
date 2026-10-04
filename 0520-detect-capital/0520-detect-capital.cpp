class Solution {
public:
bool check(string word,char s,char e){
    for(char&ch : word){
        if(ch < s || ch > e){
            return false;
        }
    }
    return true;
}



    bool detectCapitalUse(string word) {
        if(check(word,'A','Z') || check(word,'a','z') || check(word.substr(1),'a','z')){
            return true;
        }
        return false;
    }
};