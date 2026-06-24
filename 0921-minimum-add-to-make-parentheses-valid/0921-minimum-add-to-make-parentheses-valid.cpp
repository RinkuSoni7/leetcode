class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count=0;
        for(char &ch : s){
            if(ch=='('){
                count++;
                st.push(ch);
            }else{
                if(st.empty()){
                    count++;
                    st.push(ch);
                }
                else if(st.top()!='('){
                    count++;
                    st.push(ch);

                }else{
                    count--;
                    st.pop();
                }
            }

        }
        return count;
    }
};