class Solution {
public:
    bool isShipped(vector<int>& weights, int days, int capacity) {
        int time = 1, sum = 0;
        for (int weight : weights) {
            if (sum + weight > capacity) {
                time++;
                sum = 0;
            }
            sum += weight;
            if (time > days) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()); // Minimum capacity required
        int r = accumulate(weights.begin(), weights.end(), 0); // Maximum possible capacity

        while (l < r) { // Changed from `<=` to `<` to reduce unnecessary checks
            int mid = l + (r - l) / 2;
            if (isShipped(weights, days, mid)) {
                r = mid; // Instead of storing in `result`, directly modify `r`
            } else {
                l = mid + 1;
            }
        }

        return l; // The minimum required capacity
    }
};
