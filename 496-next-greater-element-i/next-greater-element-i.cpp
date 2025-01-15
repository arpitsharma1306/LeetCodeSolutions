class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]]=i;
        }
        vector<int>ans(n,-1);
        for(int j=0;j<n;j++){
            int it=mp[nums1[j]];
            cout<<it<<" ";
            for(int i=it+1;i<m;i++){
                if(nums2[i]>nums1[j]){
                    ans[j]=nums2[i];
                    break;
                }
            }
        }

        return ans;
    }
};