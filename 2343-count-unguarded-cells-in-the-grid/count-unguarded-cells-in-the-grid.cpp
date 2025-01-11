class Solution {
public:
    vector<vector<int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(vector<int>&wall:walls){
            int x=wall[0],y=wall[1];
            grid[x][y]=2;
        }
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = -1;
        }
        
        int grd=0;
        for (auto& guard : guards){
            int x=guard[0],y=guard[1];
            for(vector<int>dir:dirs){
                int new_x=x+dir[0],new_y=y+dir[1];
                while(new_x<m && new_y<n && new_x>=0 && new_y>=0){
                    if(grid[new_x][new_y]==2 || grid[new_x][new_y]==-1){
                        break;
                    }
                    if(grid[new_x][new_y]==0){
                        grid[new_x][new_y]=1;
                    }
                    new_x=new_x+dir[0];
                    new_y=new_y+dir[1];
                }
            }
        }

        int count=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) count++;
            }
        }

        return count;
    }
};