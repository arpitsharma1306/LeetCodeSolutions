class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n), suffix(n);

        prefix[0]=nums[0], suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }

        vector<int>res(n);
        res[n-1]=prefix[n-1];
        for(int i=n-2;i>=0;i--){
            res[i]=prefix[i];
            if(prefix[i]>suffix[i+1]){
                res[i]=max(res[i],res[i+1]);
            }
        }

        return res;
    }
};