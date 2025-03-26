class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        const int n = beans.size();
        if (n == 1) return 0;
        
        sort(beans.begin(), beans.end());
        
        // Calculate prefix sums
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + beans[i];
        }
        
        long long min_remove = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            // All beans before i must be removed completely (sum from 0 to i)
            // All beans after i must be reduced to beans[i] (sum from i+1 to n-1 minus (n-i-1)*beans[i])
            long long current_remove = prefix[i] + (prefix[n] - prefix[i + 1] - (long long)(n - i - 1) * beans[i]);
            min_remove = min(min_remove, current_remove);
        }
        
        return min_remove;
    }
};