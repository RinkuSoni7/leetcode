class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            if(s.find(part)==string::npos){
                break;
            }

            s.erase(s.find(part),part.length());
        }
        return s;
    }
};