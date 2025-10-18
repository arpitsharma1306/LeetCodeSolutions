class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int prev = INT_MIN;
        int cnt = 0;
        for(int i=0;i<n;i++){
            int num = nums[i]-k;
            if(prev>=num){
                if(prev<nums[i]+k){
                    num = prev+1;
                    cnt++;
                    prev = num;
                }
            }else{
                cnt++;
                prev = num;
            }
            
        }

        return cnt;
    }
};