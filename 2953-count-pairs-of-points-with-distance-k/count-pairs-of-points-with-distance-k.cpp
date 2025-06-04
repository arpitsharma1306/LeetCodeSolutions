class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k) {
        int n=c.size();
        int pairs = 0;
        unordered_map<long long,long long>mp;
        for(int i=0;i<n;i++){
            for(int val=0;val<=k;val++){
                long long x = val^c[i][0];
                long long y = (k-val)^c[i][1];
                long long key = x*1000001+y;
                if(mp.count(key)){
                    pairs+=mp[key];
                }
            }
            long long outer_key = (long long)c[i][0]*(long long)1000001+(long long)c[i][1];
            mp[outer_key]++;
        }

        return pairs;
    }
};