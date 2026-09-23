class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int closet=100000;

        for(int i=0; i<=n-3; i++){
           int s=i+1,e=n-1;

            while(s<e){
              int sum=nums[i]+nums[s]+nums[e];

              if(abs(target-sum)<abs(target-closet)){
                closet=sum;
              }

              if(sum<target)
              s++;
              else
              e--;


            }
        }

return closet;
        
    }
};