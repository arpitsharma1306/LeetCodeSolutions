class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>visit(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visit[grid[i][j]]++;
            }
        }

        vector<int>ans(2);

        for(int i=1;i<=n*n;i++){
            if(visit[i]==0){
                ans[1]=i;
            }
            if(visit[i]==2){
                ans[0]=i;
            }
        }

        return ans;
    }
};