class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        int pCount[26] = {0};
        int sCount[26] = {0};

        // Count characters in p
        for (int i = 0; i < p.length(); i++) {
            pCount[p[i] - 'a']++;
        }

        int windowSize = p.length();

        // First window
        for (int i = 0; i < windowSize; i++) {
            sCount[s[i] - 'a']++;
        }

        // Check first window
        bool same = true;

        for (int i = 0; i < 26; i++) {
            if (pCount[i] != sCount[i]) {
                same = false;
                break;
            }
        }

        if (same)
            ans.push_back(0);

        // Sliding window
        for (int right = windowSize; right < s.length(); right++) {

            // Add new character
            sCount[s[right] - 'a']++;

            // Remove old character
            int left = right - windowSize;
            sCount[s[left] - 'a']--;

            // Compare frequencies
            same = true;

            for (int i = 0; i < 26; i++) {
                if (pCount[i] != sCount[i]) {
                    same = false;
                    break;
                }
            }

            if (same)
                ans.push_back(left + 1);
        }

        return ans;
    }
};