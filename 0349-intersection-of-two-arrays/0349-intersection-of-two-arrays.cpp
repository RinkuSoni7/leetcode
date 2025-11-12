class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>result;
        unordered_set<int>s1;
        for(int i=0; i<nums1.size(); i++){
            s1.insert(nums1[i]);
        }
        for(int num : nums2){
            if(s1.count(num)){
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};