
class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {

            string word = words[i];

            for (int j = 0; j < word.length(); j++) {
                word[j] = tolower(word[j]);
            }

            string row;

            if (row1.find(word[0]) != string::npos) {
                row = row1;
            }
            else if (row2.find(word[0]) != string::npos) {
                row = row2;
            }
            else {
                row = row3;
            }

            bool flag = true;

            for (int j = 0; j < word.length(); j++) {

                if (row.find(word[j]) == string::npos) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
