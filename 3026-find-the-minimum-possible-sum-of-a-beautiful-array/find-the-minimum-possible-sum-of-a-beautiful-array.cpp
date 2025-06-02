class Solution {
public:
    int mod = 1e9 + 7;
    int minimumPossibleSum(int n, int target) {
        long long k=min(n,target/2);
        long long rem = n-k;
        long long sum1 = k*(k+1)/2;
        long long start = target;
        long long end = target + rem - 1;
        long long sum2 = rem * (start+end)/2;

        long long total = (sum1%mod+sum2%mod)%mod;
        return static_cast<int>(total);
    }
};