class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Generate all prime numbers less than 1000 using the Sieve of Eratosthenes
        vector<int> primes;
        vector<bool> isPrime(1000, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        for (int i = 2; i < 1000; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * i; j < 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Traverse the array from left to right and apply the prime subtraction operation
        int prev = 0; // Initialize `prev` to keep track of the last valid element
        for (int num : nums) {
            // Find the largest prime `p` such that `num - p > prev`
            auto it = upper_bound(primes.begin(), primes.end(), num - prev - 1);
            if (it != primes.begin()) {
                --it; // Move to the largest valid prime less than `num - prev`
                num -= *it;
            }

            // Check if the current element is strictly greater than `prev`
            if (num <= prev) {
                return false;
            }

            // Update `prev` for the next iteration
            prev = num;
        }

        return true;
    }
};
