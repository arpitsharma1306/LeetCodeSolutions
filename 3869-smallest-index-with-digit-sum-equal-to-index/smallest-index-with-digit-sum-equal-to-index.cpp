class Solution {
public:
    int digit_sum(int n){
        int sum=0;
        while(n){
            sum+=(n%10);
            n/=10;
        }

        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=digit_sum(nums[i]);
            if(sum==i) return i;
        }

        return -1;
    }
};