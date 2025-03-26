#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        if (n == 1) return 0;

        sort(beans.begin(), beans.end());

        long long total_sum = 0;
        for (int& bean : beans) total_sum += bean;

        long long min_remove = total_sum;
        
        for (int i = 0; i < n; i++) {
            long long keep = (long long) beans[i] * (n - i);
            min_remove = min(min_remove, total_sum - keep);
        }

        return min_remove;
    }
};
