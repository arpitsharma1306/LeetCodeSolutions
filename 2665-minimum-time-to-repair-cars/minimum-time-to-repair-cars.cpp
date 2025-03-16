class Solution {
public:
    bool canRepairAll(vector<int>& ranks, int cars, long long time) {
        long long total_cars = 0;
        for (int rank : ranks) {
            total_cars += sqrt(time / rank);
            if (total_cars >= cars) return true; // Stop early if we meet the requirement
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long min_rank = *min_element(ranks.begin(), ranks.end());
        long long low = 1, high = min_rank * (long long)cars * cars, ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canRepairAll(ranks, cars, mid)) {
                ans = mid;
                high = mid - 1; // Try for a smaller time
            } else {
                low = mid + 1; // Increase the search range
            }
        }
        return ans;
    }
};
