class Solution {
public:
    int n;
    int findMax(vector<int>& nums){
        int sum = 0;
        int maxi=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }

        return maxi;
    }

    int findMin(vector<int>& nums){
        int sum=0;
        int mini=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mini=min(mini,sum);
            if(sum>0) sum=0;
        }

        return mini;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        n=nums.size();
        bool negative = true;
        for(int &num:nums){
            if(num>=0) negative=false;
        }

        if(negative) return *max_element(nums.begin(),nums.end());

        int max_sum = findMax(nums);
        int min_sum = findMin(nums);
        int total = accumulate(nums.begin(),nums.end(),0);

        return max(max_sum,total-min_sum);

    }
};