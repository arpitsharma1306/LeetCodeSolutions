class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0;
        int max_seen = -1;
        for (int i = 0; i < n; i++) {
            max_seen = max(max_seen, arr[i]);
            if (max_seen == i)
                chunks++;
        }

        return chunks;
    }
};