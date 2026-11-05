class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      set<int>st;
        for(int i : nums){
            st.insert(i);
        }

    
        int index=0;
        for(auto it : st){
            nums[index]=it;
            index++;
        }

        return index;
    }
};