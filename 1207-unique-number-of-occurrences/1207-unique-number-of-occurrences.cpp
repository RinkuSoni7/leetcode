class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>count(20001,0);
        for(int num : arr){
            count[num+1000]++;
        }

        sort(count.begin(),count.end());

        for(int i=0; i<count.size()-1; i++){
            if(count[i]!=0 && count[i]==count[i+1]){
                return false;
            }
        }
        return true;
       
    }
};
