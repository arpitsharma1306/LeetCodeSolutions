class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;

        while (s.size() > 1) {
            if (s.back() == '1') {
                // Binary Add 1
                int i = s.size() - 1;
                bool found = false;

                while (i >= 0) {
                    if (s[i] == '1') {
                        s[i] = '0';
                    } else {
                        s[i] = '1';
                        found = true;
                        break;
                    }
                    i--;
                }

                if (!found) {
                    s.insert(s.begin(), '1'); // simulate carry overflow
                }
            } else {
                // Binary Divide by 2 (right shift)
                s.pop_back();
            }

            cnt++;
        }

        return cnt;
    }
};
