#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    int minJumps(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Find the maximum value in nums to determine the sieve's size
        int max_val = 0;
        for (int x : nums) {
            if (x > max_val) max_val = x;
        }

        // 1. Sieve to find the Smallest Prime Factor (SPF) for all numbers up to max_val
        std::vector<int> spf(max_val + 1);
        for (int i = 0; i <= max_val; ++i) spf[i] = i;
        for (int i = 2; i * i <= max_val; ++i) {
            if (spf[i] == i) { // i is a prime number
                for (int j = i * i; j <= max_val; j += i) {
                    if (spf[j] == j) spf[j] = i; // Set SPF for multiples of i
                }
            }
        }
        
        // 2. Map from a prime to all indices in nums whose value is a multiple of that prime
        std::unordered_map<int, std::vector<int>> prime_to_multiple_indices;
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if (val <= 1) continue;
            // Extract unique prime factors and add the current index to their lists
            while (val > 1) {
                int p = spf[val];
                prime_to_multiple_indices[p].push_back(i);
                while (val > 1 && val % p == 0) {
                    val /= p;
                }
            }
        }

        // 3. Optimized BFS
        std::queue<std::pair<int, int>> q;
        q.push({0, 0}); // {index, jumps}

        std::vector<bool> vis_idx(n, false);
        vis_idx[0] = true;
        
        // Keep track of primes whose jump connections have already been explored
        std::vector<bool> vis_prime(max_val + 1, false);

        while (!q.empty()) {
            auto [idx, jumps] = q.front();
            q.pop();

            if (idx == n - 1) return jumps;

            // Jump Type 1: Adjacent indices
            if (idx + 1 < n && !vis_idx[idx + 1]) {
                vis_idx[idx + 1] = true;
                q.push({idx + 1, jumps + 1});
            }
            if (idx - 1 >= 0 && !vis_idx[idx - 1]) {
                vis_idx[idx - 1] = true;
                q.push({idx - 1, jumps + 1});
            }

            // Jump Type 2: Prime jumps
            int p = nums[idx];
            if (p > 1 && spf[p] == p) { // Check if nums[idx] is a prime
                if (!vis_prime[p]) {
                    vis_prime[p] = true; // Mark this prime's connections as processed
                    if (prime_to_multiple_indices.count(p)) {
                        // Add all unvisited indices that are multiples of p to the queue
                        for (int target_idx : prime_to_multiple_indices[p]) {
                            if (!vis_idx[target_idx]) {
                                vis_idx[target_idx] = true;
                                q.push({target_idx, jumps + 1});
                            }
                        }
                    }
                }
            }
        }

        return n-1;
    }
};