class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int r1=-1,r2=m,c1=-1,c2=n;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    r1=max(r1,i);
                    r2=min(r2,i);
                    c1=max(c1,j);
                    c2=min(c2,j);
                }
            }
        }
int ans=0;
        if(r1-r2>=0&&c1-c2>=0){
            ans=(r1-r2+1)*(c1-c2+1);
        }
  return ans;
    }
};