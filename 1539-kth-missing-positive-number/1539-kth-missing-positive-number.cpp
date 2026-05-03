class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int num=1;
        int i=0;

        for(int i=0; i<n;){
            
            if(arr[i]==num){
                i++;
            }else{
                k--;
                if(k==0) return num;
                }
                num++;
            }

        while(k--){
            num++;
        }

        return num-1;

        
    }
};