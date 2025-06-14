class Solution {
public:
    bool check(vector<int>& nums, int p,int maxi){
        int pairs = 0;
        for(int i=0;i<nums.size()-1;){
            if(pairs>=p) return true;
            if(nums[i+1]-nums[i]<=maxi){
                pairs++;
                i+=2;
            }else{
                i++;
            }
        }
        if(pairs>=p) return true;

        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int right = nums.back() - nums[0];
        int left = 0;
        int ans = right;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(check(nums,p,mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return ans;
    }
};