class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        bool negative = true;
        int total = 0;
        for(int &num:nums){
            total+=num;
            if(num>=0) negative=false;
        }

        if(negative) return *max_element(nums.begin(),nums.end());

        int sum1 = 0, sum2 = 0;
        int maxi=0, mini=0;;

        for(int i=0;i<n;i++){
            sum1+=nums[i];
            sum2+=nums[i];
            maxi=max(maxi,sum1);
            mini=min(mini,sum2);

            if(sum1<0) sum1=0;
            if(sum2>0) sum2=0;

        }

        return max(maxi,total-mini);

    }
};