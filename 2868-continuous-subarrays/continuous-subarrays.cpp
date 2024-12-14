class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        long long ans = 0;
        multiset<int> st;

        while (i < n) {

            while (j < n &&
                   (st.size() == 0 ||
                    max(nums[j], *(--st.end())) - min(nums[j], *st.begin()) <=
                        2)) {
                st.insert(nums[j]);
                j++;
            }

            ans += st.size();

            st.erase(st.find(nums[i]));
            i++;
        }

        return ans;
    }
};