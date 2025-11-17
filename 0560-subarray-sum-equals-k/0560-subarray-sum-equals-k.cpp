class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        int prefixsum=0;

        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0; i<n; i++){
            prefixsum +=nums[i];
            if(m.count(prefixsum-k)){
                total +=m[prefixsum-k];
                m[prefixsum]++;
            }else{
                m[prefixsum]++;
            }
        }
        return total;


        
    }
};