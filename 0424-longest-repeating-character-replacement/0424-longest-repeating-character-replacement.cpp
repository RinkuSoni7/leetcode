class Solution {
public:
    int characterReplacement(string s, int k) {

        map<char, int> freq;

        int left = 0;
        int right = 0;

        int maxFreq = 0;
        int ans = 0;

        while (right < s.length()) {

            freq[s[right]]++;

          
            maxFreq = 0;

            for (auto it : freq) {
                maxFreq = max(maxFreq, it.second);
            }

            int windowSize = right - left + 1;
            int replacements = windowSize - maxFreq;

            while (replacements > k) {

                freq[s[left]]--;
                left++;

                
                maxFreq = 0;

                for (auto it : freq) {
                    maxFreq = max(maxFreq, it.second);
                }

                windowSize = right - left + 1;
                replacements = windowSize - maxFreq;
            }

            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};