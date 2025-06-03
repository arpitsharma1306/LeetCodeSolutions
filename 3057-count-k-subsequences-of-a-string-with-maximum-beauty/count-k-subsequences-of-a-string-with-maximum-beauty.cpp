class Solution {
public:
    unordered_map<int, int>freq;
    vector<int>power;
    int reqLen;
    unordered_map<string, int>seen;
    int mod = 1e9 + 7;
    int dp[26][26];
    long long int solve( int i, int k){
        if(i == power.size()){
            return k == reqLen;
        }
        if(k > reqLen)return 0;
        if(dp[i][k] != -1)return dp[i][k];
        long long int take = 0, notake = 0;
        if(power[i] == power[k])
        take = power[i] * solve(i + 1, k + 1);
        notake = solve( i + 1, k);
        return dp[i][k] = (take + notake) % mod;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int n = s.size();
        for(auto c: s)freq[c]++;
        reqLen = k;
        memset(dp, -1, sizeof(dp));
        if(k > freq.size() || k > 26)return 0;
        for(auto m: freq){
            power.push_back(m.second);
        }
        sort(power.rbegin(), power.rend());
        return solve( 0, 0); 
    }
};