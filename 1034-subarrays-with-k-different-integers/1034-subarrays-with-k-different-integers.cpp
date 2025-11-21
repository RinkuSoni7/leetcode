class Solution {
public:
    long long atMostK(vector<int>& nums, int K) {
        unordered_map<int,int> freq;
        long long ans = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            freq[nums[end]]++;

            while (freq.size() > K) {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0)
                    freq.erase(nums[start]);
                start++;
            }
            
            ans += (end - start + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int K) {
        return atMostK(nums, K) - atMostK(nums, K - 1);
    }
};
