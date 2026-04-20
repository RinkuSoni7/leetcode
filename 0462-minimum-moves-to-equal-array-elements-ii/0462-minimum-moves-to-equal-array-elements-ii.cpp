class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int count = 0;

        int mid = n / 2;

        while (i < n) {
            if (nums[i] < nums[mid]) {
                count += nums[mid] - nums[i];
            }
            else if (nums[i] > nums[mid]) {
                count += nums[i] - nums[mid];
            }
            else {
                count += 0;
            }

            i++;
        }

        return count;
    }
};