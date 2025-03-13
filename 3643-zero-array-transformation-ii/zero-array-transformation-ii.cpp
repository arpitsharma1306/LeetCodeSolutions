class Solution {
public:
    bool isValid(int m,vector<int>&nums, vector<vector<int>>& queries){
        int n=nums.size();
        vector<int>prefix(n+1,0);

        for(int i=0;i<m;i++){
            int l=queries[i][0], r=queries[i][1], val=queries[i][2];

            prefix[l]+=val;
            if(r+1<n) prefix[r+1]-=val;
        }

        int preSum=0;
        for(int i=0;i<n;i++){
            preSum+=prefix[i];
            if(preSum<nums[i]) return false;
        }

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int low=0, high=queries.size();
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(mid,nums,queries)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
        
    }
};