class Solution {
public:
    string compressedString(string word) {
        string s = "";
        int n = word.length();
        int cnt = 1;
        char ch = word[0];
        for (int i = 1; i < n; i++) {
            if (word[i] == ch && cnt < 9)
                cnt++;

            else {
                s.push_back(cnt + '0');
                s.push_back(ch);
                ch = word[i];
                cnt = 1;
            }
        }
        s.push_back('0' + cnt);
        s.push_back(ch);

        return s;
    }
};