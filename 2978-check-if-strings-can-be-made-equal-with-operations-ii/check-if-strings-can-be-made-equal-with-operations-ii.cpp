class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        vector<int>freq1o(26,0), freq1e(26,0), freq2o(26,0), freq2e(26,0);

        for(int i=0;i<n;i+=2){
            freq1e[s1[i]-'a']++;
            freq2e[s2[i]-'a']++;
        }
        for(int i=1;i<n;i+=2){
            freq1o[s1[i]-'a']++;
            freq2o[s2[i]-'a']++;
        }

        if(freq1e==freq2e && freq1o==freq2o) return true;

        return false;
    }
};