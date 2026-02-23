class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length()!=goal.length()){
            return false;
        }
        string ans=s+s;
        

        


        for(int i=0; i<ans.length()-goal.length(); i++){
            if(ans.substr(i,goal.length())==goal){
                return true;
            }
        }

            return false;
        
    }
};