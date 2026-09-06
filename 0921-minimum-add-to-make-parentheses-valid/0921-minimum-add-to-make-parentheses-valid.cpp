class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        int count=0;
        stack<char>st;
        for(char &ch : s){
            if(ch=='('){
                st.push(ch);
                count++;
            }
            else if(st.empty()){
                st.push(ch);
                count++;
            }
            else if(st.top()!='('){
                st.push(ch);
                count++;
            }
            else{
                st.pop();
                count--;
            }
        }
        return count;
    }
};