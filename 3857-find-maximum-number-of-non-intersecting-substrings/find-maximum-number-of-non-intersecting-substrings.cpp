class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        if (n < 4)
            return 0;
        int cnt = 0;
        unordered_set<char> st;
        unordered_map<char, int> mp;
        st.insert(word[0]);
        mp[word[1]] = 2;
        if(word[1]!=word[2]) mp[word[2]] = 1;

        for (int i = 3; i < n; i++) {
            if (st.find(word[i]) != st.end()) {
                cnt++;
                st.clear();
                mp.clear();
                continue;
            }

            for (auto it = mp.begin(); it != mp.end();) {
                it->second += 1;
                if (it->second == 3) {
                    st.insert(it->first);
                    it = mp.erase(it); // returns iterator to next element
                } else {
                    ++it;
                }
            }
            if(mp.find(word[i])!=mp.end()) continue;

            mp[word[i]]=1;
        }

        return cnt;
    }
};