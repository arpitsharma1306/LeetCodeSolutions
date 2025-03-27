class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int cells=n*n;
        if(w>maxWeight) return 0;
        int low=1,high=cells;
        int ans=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid*w<=maxWeight){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};