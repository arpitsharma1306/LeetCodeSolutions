class Solution {
public:
    int n;
    vector<vector<int>>t;
    int solve(vector<int>& nums1, vector<int>& nums2,int swapped,int i){
        if(i>=n) return 0;
        if(t[i][swapped]!=-1) return t[i][swapped];
        int prev1 = (swapped==1)?nums2[i-1]:nums1[i-1];
        int prev2 = (swapped==1)?nums1[i-1]:nums2[i-1];
        int ans = INT_MAX;
        if(prev1<nums1[i] && prev2<nums2[i]) ans = solve(nums1,nums2,0,i+1);
        if(prev1<nums2[i] && prev2<nums1[i]) ans = min(ans,1+solve(nums1,nums2,1,i+1));
        return t[i][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        t.resize(n,vector<int>(2,-1));
        return min(solve(nums1,nums2,0,1),1+solve(nums1,nums2,1,1));
    }
};