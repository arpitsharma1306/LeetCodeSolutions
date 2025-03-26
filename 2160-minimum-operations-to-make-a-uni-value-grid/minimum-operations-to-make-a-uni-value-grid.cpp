class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(), n=grid[0].size();
        vector<int>nums;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(begin(nums),end(nums));
        n=nums.size();
        int operations=0;
        int mid = nums[n/2];

        for(int& num:nums){
            int gap=abs(mid-num);
            if(gap%x!=0) return -1;
            operations+=(gap/x);
        }

        return operations;
        
    }
};