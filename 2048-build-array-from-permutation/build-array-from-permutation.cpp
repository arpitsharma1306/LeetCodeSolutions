class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]+=1002*(nums[nums[i]]%1002);
        }

        for(int i=0;i<n;i++) nums[i]/=1002;
        return nums;
    }
};