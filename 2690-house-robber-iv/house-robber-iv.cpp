class Solution {
public:
    bool isPossible(vector<int>&nums,int k,int cap){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=cap){
                cnt++;
                i++;
                if(cnt>=k) return true;
            }
        }

        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();

        int low=*min_element(begin(nums),end(nums));
        int high=*max_element(begin(nums),end(nums));
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
};