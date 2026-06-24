class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        stack<char>st1;

        for(int i=0; i<s.length(); i++){
        
            if(s[i]=='#'){
                if(!st.empty())
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }



        for(int i=0; i<t.length(); i++){
            
            if(t[i]=='#'){
                if(!st1.empty())
                st1.pop();
            }
            else{
                st1.push(t[i]);
            }
        }


if(st.size()!=st1.size()) return false;

while(!st.empty()){
    if(st.top()!=st1.top()) return false;

    st.pop();
    st1.pop();

}

return true;






    }
};