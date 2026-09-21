class Solution {
public:
    int maxVowels(string s, int k) {

        int count = 0;

        // Count vowels in first window
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }
        }

        int maxVowels = count;

        // Slide the window
        for (int i = k; i < s.length(); i++) {

            // Add new character
            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }

            // Remove old character
            if (s[i - k] == 'a' || s[i - k] == 'e' ||
                s[i - k] == 'i' || s[i - k] == 'o' ||
                s[i - k] == 'u') {
                count--;
            }

            maxVowels = max(maxVowels, count);
        }

        return maxVowels;
    }
};