class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>mp;
       vector<int>result;
       
       for(int i=0; i<nums1.size(); i++){
        mp[nums1[i]]++;
       }
       

       for(auto &num : nums2){
        if(mp.find(num)!=mp.end()){
            result.push_back(num);
            mp.erase(num);
        }
        
       }
       return result;

    }
};