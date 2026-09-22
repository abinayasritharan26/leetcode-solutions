class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];

        for (int i = 0; i < 256; i++) {
            last[i] = -1;
        }

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            char ch = s[right];

            if (last[ch] >= left) {
                left = last[ch] + 1;
            }

            last[ch] = right;

            int len = right - left + 1;

            if (len > maxLen) {
                maxLen = len;
            }
        }

        return maxLen;
    }
};