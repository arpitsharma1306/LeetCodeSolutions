class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int mini = nums[k];
        int left=k, right=k;
        int max_score = mini;
        while(left>0 || right<nums.size()-1){
            if(left==0 || (right<nums.size()-1 && nums[left-1]<nums[right+1])){
                right++;
            }else{
                left--;
            }

            mini = min(mini,min(nums[left],nums[right]));
            max_score = max(max_score,mini*(right-left+1));
        }

        return max_score;
    }
};