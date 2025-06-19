class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int i=0;
        while(i<n){
            int j=i+1;
            for(;j<n;j++){
                if(nums[j]-nums[i]<=k) continue;
                break;
            }
            if(j<n) cnt++;
            i=j;
        }

        return cnt;
    }
};