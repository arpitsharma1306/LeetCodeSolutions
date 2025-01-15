class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int>nge(m,-1);
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()) nge[i]=st.top();
            st.push(nums2[i]);
        }

        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]]=nge[i];
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            ans[i]=mp[nums1[i]];
        }

        return ans;
    }
};