class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];

        vector<int>t1(n+1,0);
        vector<int>t2(n+1,0);
        t1[1]=nums[0];
        for(int i=2;i<n;i++){
            int steal=nums[i-1]+t1[i-2];
            int skip=t1[i-1];
            t1[i]=max(steal,skip);
        }
        t1[n]=t1[n-1];

        t2[1]=0;
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+t2[i-2];
            int skip=t2[i-1];
            t2[i]=max(steal,skip);
        }

        return max(t1[n],t2[n]);
    }
};