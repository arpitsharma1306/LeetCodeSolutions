class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long zeroes1 = count(nums1.begin(), nums1.end(), 0);
        long long zeroes2 = count(nums2.begin(), nums2.end(), 0);
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);

        
        if((zeroes1==0 && sum2+zeroes2>sum1+zeroes1) || (zeroes2==0 && sum1+zeroes1>sum2+zeroes2)) return -1;
        long long res1 = sum1+zeroes1;
        long long res2 = sum2+zeroes2;
        return max(res1,res2);
    }
};