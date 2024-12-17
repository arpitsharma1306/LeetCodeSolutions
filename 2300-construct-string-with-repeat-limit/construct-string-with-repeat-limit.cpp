class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>> pq;

        vector<int> v(26, 0);
        for (char& ch : s) {
            v[ch - 'a']++;
        }

        int idx = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (v[idx] > 0) {
                pq.push({ch, v[idx]});
            }
            idx++;
        }

        string str = "";
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();

            char ch1 = cell.first;
            int freq1 = cell.second;

            if (freq1 > repeatLimit) {
                str.append(repeatLimit, ch1);
                freq1 -= repeatLimit;
                if (pq.empty())
                    break;
                else {
                    auto cell2 = pq.top();
                    pq.pop();
                    char ch2 = cell2.first;
                    int freq2 = cell2.second;
                    str.append(1, ch2);
                    freq2 -= 1;
                    if (freq2 > 0) {
                        pq.push({ch2, freq2});
                    }
                }
                pq.push({ch1, freq1});
            } else {
                str.append(freq1, ch1);
            }
        }

        return str;
    }
};