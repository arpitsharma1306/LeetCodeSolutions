class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int ans=0;
        if(m%2==1){
            ans = accumulate(nums1.begin(),nums1.end(),0,bit_xor<int>());
        }
        if(n%2==1){
            ans ^= accumulate(nums2.begin(),nums2.end(),0,bit_xor<int>());
        }

        return ans;
    }
};