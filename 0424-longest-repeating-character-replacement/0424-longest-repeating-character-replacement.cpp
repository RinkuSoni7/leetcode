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

            // Maximum frequency
            maxFreq = max(maxFreq, freq[s[right]]);

            // Current window size
            int windowSize = right - left + 1;

            // Characters that need replacement
            int replacements = windowSize - maxFreq;

            // Window invalid hai
            while (replacements > k) {

                freq[s[left]]--;

                left++;

                windowSize = right - left + 1;
                replacements = windowSize - maxFreq;
            }

            // Answer update
            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};