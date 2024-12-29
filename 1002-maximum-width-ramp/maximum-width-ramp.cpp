class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxRight(n);
        maxRight[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxRight[i]=max(maxRight[i+1],nums[i]);
        }

        int width=0;
        int i=0,j=0;
        while(j<n){
            while(i<j && nums[i]>maxRight[j]){
                i++;
            }
            width=max(width,j-i);
            j++;
        }
        return width;
    }
};