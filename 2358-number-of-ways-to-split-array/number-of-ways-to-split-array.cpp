class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>Prefix(n+1,0);
        for(int i=0;i<n;i++){
            Prefix[i+1]=Prefix[i]+nums[i];
        }
        int count=0;
        for(int i=1;i<n;i++){
            if(Prefix[i]>=Prefix[n]-Prefix[i]){
                count++;
            }
        }

        return count;
    }
};