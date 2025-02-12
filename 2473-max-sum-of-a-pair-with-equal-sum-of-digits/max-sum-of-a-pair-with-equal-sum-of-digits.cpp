class Solution {
public:
    int digitsum(int num){
        int sum=0;
        while(num>0){
            int digit=num%10;
            sum+=digit;
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int result=-1;
        for(int i=0;i<n;i++){
            int sum=digitsum(nums[i]);
            if(!mp.empty() && mp.find(sum)!=mp.end()){
                int num2=mp[sum];
                if(nums[i]>num2){
                    mp[sum]=nums[i];
                }
                result=max(result,num2+nums[i]);
            }else{
                mp[sum]=nums[i];
            }
        }

        return result;
    }
};