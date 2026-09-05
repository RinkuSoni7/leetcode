class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        int count=0;
        stack<char>st;
        for(char ch : s){
            if(st.empty()){
                count++;
                st.push(ch);
                
            }
            else if(ch=='('){
                count++;
                st.push(ch);
                
            }
            else if(st.top()!='('){
                 count++;
                    st.push(ch);
                   
                }
                else{
                    count--;
                    st.pop();
                }
            
        }
        return count;
    }
};