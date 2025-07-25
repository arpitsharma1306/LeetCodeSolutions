class Solution {
public:
    long long MOD = 1e9 + 7;
    // MAX needs to be at least 2*n + 1. For n=500, it must be at least 1001.
    const int MAX = 1001; 
    vector<long long> fact;

    // The power function for modular exponentiation is correct.
    long long power(long long x, long long y) {
        long long res = 1;
        x %= MOD;
        while (y > 0) {
            if (y & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }

    // Helper to calculate modular inverse using the power function
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }
    
    // Precompute factorials up to 2*n
    void precompute(int n) {
        fact.resize(2 * n + 1);
        fact[0] = 1;
        for (int i = 1; i <= 2 * n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
    }

    // The solve function contained the main logical errors
    long long calculate_orders(int n) {
        // The correct formula is (2n)! / 2^n
        // In modular arithmetic, this is (fact[2*n] * modInverse(2^n)) % MOD

        // 1. Numerator is (2n)!
        long long numerator = fact[2 * n];

        // 2. Denominator is 2^n
        long long denominator = power(2, n);
        
        // 3. Modular inverse of the denominator
        long long inv_denominator = modInverse(denominator);

        // 4. Final answer
        long long ans = (numerator * inv_denominator) % MOD;
        return ans;
    }

    int countOrders(int n) {
        // Precompute the necessary factorials
        precompute(n);
        
        // Calculate the result using the correct formula
        return calculate_orders(n);
    }
};