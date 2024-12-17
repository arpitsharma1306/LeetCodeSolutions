class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int countFreshOrange = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    countFreshOrange++;
                }
            }
        }
        if(countFreshOrange==0) return 0;

        int time=0;
        vector<vector<int>>dir{{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto cell=q.front();
                q.pop();

                for(auto &it:dir){
                    int x=cell.first+it[0];
                    int y=cell.second+it[1];
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            time++;
            
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return time-1;
    }
};