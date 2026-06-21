class Solution {
public:
char solve( vector<char> &value,char op){
    if(op=='!'){
        return value[0]=='t' ? 'f' : 't';
        
    }

    if(op=='&'){
        for(char &ch : value){
            if(ch=='f'){
                return 'f';
            }
        }
        return 't';
    }

    if(op=='|'){
        for(char &ch : value){
            if(ch=='t'){
                return 't';
            }
        }
        return 'f';
    }
    return 'f';


}

    bool parseBoolExpr(string expression) {
        stack<char>st;
        int n=expression.size();

        for(int i=0; i<n; i++){
            if(expression[i]==',') continue;
            if(expression[i]==')'){
                vector<char>value;
                while(st.top()!='('){
                    value.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();

                st.push(solve(value,op));
            }
            else{
                st.push(expression[i]);
            }

        }

        return st.top() == 't' ? true : false;


    }
};