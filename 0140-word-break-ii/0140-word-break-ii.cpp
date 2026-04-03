class Solution {
public:

vector<string> result;
unordered_set<string> st;


void solve(int index,string currSentence,string s){
    if(index>=s.length()){
        result.push_back(currSentence);
        return;
    }



    for(int i=index; i<s.length(); i++){
        string temp=s.substr(index,i-index+1);

        if(st.count(temp)){
            string tempsentence=currSentence;
            if(!currSentence.empty()){
                currSentence+=" ";
            }

            currSentence+=temp;
            solve(i+1,currSentence,s);

            currSentence=tempsentence; // remove temp;
        }
    }



}


    vector<string> wordBreak(string s, vector<string>& wordDict) {

        for(string& word : wordDict){
            st.insert(word);
        }
        
        string currSentence = "";

        solve(0,currSentence,s);
        return result;


    }
};