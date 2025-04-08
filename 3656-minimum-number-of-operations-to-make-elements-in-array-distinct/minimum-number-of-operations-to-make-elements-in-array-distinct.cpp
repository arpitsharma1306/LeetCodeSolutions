class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(101,0);
        int operations=0;
        for(int& num:nums){
            freq[num]++;
        }
        int j=0;
        for(int i=1;i<=100;i++){
            while(freq[i]>1 && j<n){
                if(j<n) freq[nums[j++]]--;
                if(j<n) freq[nums[j++]]--;
                if(j<n) freq[nums[j++]]--;
                operations++;
            }
        }

        return operations;
    }
};