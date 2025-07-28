class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        int mod = 1e9+7;
        unordered_map<int,int>freq;
        for(auto &x:points){
            freq[x[1]]++;
        }
        vector<long long>lines;
        for(auto &it:freq){
            if(it.second<2) continue;
            long long p=it.second;
            long long line =  p*(p-1)/2;
            lines.push_back(line);
        }

        long long sum = 0, sumSq = 0;
        for (long long &x : lines) {
            sum = (sum + x) % mod;
            sumSq = (sumSq + x * x % mod) % mod;
        }

        long long ans = (sum * sum % mod - sumSq + mod) % mod;
        ans = ans * ((mod + 1) / 2) % mod;  // division by 2 modulo mod

        return (int)ans;
    }
};