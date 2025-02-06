class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]!=nums[j]){
                    int prd=nums[i]*nums[j];
                    mp[prd]++;
                }
            }
        }
        int count=0;
        for(auto &it:mp){
            if(it.second>1){
                int val=it.second;
                int combinations = (val * (val-1)) / 2;
                count+=(combinations*8);
            }
        }

        return count;
    }
};