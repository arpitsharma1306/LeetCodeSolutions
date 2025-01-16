class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left_max(n,0);
        vector<int>right_max(n,0);
        left_max[0]=height[0];
        right_max[n-1]=height[n-1];
        int left=height[0];
        int right=height[n-1];
        for(int i=1;i<n;i++){
            left_max[i]=left;
            left=max(left,height[i]);
        }
        for(int i=n-2;i>=0;i--){
            right_max[i]=right;
            right=max(right,height[i]);
        }

        int water=0;
        for(int i=0;i<n;i++){
            int len=min(left_max[i],right_max[i])-height[i];
            if(len>0) water+=len;
        }

        return water;
    }
};