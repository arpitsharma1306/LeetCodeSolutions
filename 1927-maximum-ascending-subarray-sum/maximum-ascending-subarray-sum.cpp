class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];

        int temp=nums[0];
        for(int i=1;i<=n;i++){
            if(i==n||nums[i]<=nums[i-1]){
                maxi=max(temp,maxi);
                if(i!=n)
                 temp=nums[i];
            }
            else{
                temp+=nums[i];
            }
            
        }
        return maxi;
    }
};