class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> num(26,0);
        for(int i=0; i<s.size(); i++)
        {
            num[s[i] - 'a']++;
        }
        int max_cons = 0, max_vow = 0;
        for(int i=0; i<26; i++)
        {
            if( i == 0 || i ==4 || i == 8 || i == 14 || i == 20)
                max_vow = max(max_vow , num[i]);
            else
                max_cons = max(max_cons , num[i]);
        }
        return max_vow + max_cons;
        
    }
};