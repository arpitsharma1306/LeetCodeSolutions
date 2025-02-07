class Solution {
public:
    bool isPossible(vector<int>& piles, int speed, int h) {
        long long time = 0;
        for (int pile : piles) {
            time += (pile + speed - 1) / speed;  // Equivalent to ceil(pile / speed)
            if (time > h) return false; // Early exit to optimize
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(piles, mid, h)) {
                ans = mid;
                r = mid - 1; // Try a smaller speed
            } else {
                l = mid + 1; // Increase speed
            }
        }
        return ans;
    }
};
