class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) {
            return false;
        }

        int count1[26] = {0};
        int count2[26] = {0};

        // Count characters of s1
        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;
        }

        int window = s1.length();

        // First window
        for (int i = 0; i < window; i++) {
            count2[s2[i] - 'a']++;
        }

        // Check first window
        bool same = true;

        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                same = false;
                break;
            }
        }

        if (same) {
            return true;
        }

        // Sliding window
        for (int right = window; right < s2.length(); right++) {

            // Add new character
            count2[s2[right] - 'a']++;

            // Remove old character
            int left = right - window;
            count2[s2[left] - 'a']--;

            // Compare frequencies
            same = true;

            for (int i = 0; i < 26; i++) {
                if (count1[i] != count2[i]) {
                    same = false;
                    break;
                }
            }

            if (same) {
                return true;
            }
        }

        return false;
    }
};