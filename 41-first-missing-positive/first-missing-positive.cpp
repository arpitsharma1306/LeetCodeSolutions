class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.erase(remove_if(nums.begin(),nums.end(), [](int n){
            return n<=0;
        }), nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            if(num<=n){
                if(nums[num-1]>0){
                    nums[num-1] = -nums[num-1];
                }
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }

        return n+1;
    }
};