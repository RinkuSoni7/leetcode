class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
            int index=0;

            int i=0;

        while(i<n){
            int count=0;
            char ch=chars[i];
        
            while(i<n && ch==chars[i]){  
                count++;
                i++;
            }
            chars[index]=ch;
            index++;

            if(count>1){
                string number=to_string(count);
                for(char &num : number){
                    chars[index]=num;
                    index++;
                }
            }

        }

        return index;
        
    }
};