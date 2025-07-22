class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int l=0,r=1;
        unordered_set<int>st;
        int sum=nums[0];
        int ans = sum;
        st.insert(nums[0]);
        while(r<n){
            while(!st.empty() && st.find(nums[r])!=st.end()){
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            st.insert(nums[r]);
            sum+=nums[r];
            r++;
            ans = max(ans,sum);
        }

        return ans;
    }
};