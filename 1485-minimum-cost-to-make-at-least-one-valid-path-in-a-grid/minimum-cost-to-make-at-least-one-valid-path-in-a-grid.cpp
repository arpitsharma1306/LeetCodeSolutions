class Solution {
public:
    int m,n;
    bool isValid(int x,int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
    int findDir(int i,int j,int x,int y,vector<vector<int>>& grid){
        if(x==0 && y==1 && grid[i][j]==1) return 0;
        else if(x==0 && y==-1 && grid[i][j]==2) return 0;
        else if(x==1 && y==0 && grid[i][j]==3) return 0;
        else if(x==-1 && y==0 && grid[i][j]==4) return 0;
        else{
            return 1;
        }
    }
    vector<vector<int>>dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>costs(m,vector<int>(n,INT_MAX));
        costs[0][0]=0;
        deque<vector<int>>dq;
        dq.push_front({0,0,0}); //cost,{i,j}
        while(!dq.empty()){
            auto node = dq.front();
            dq.pop_front();
            int cost=node[0],x=node[1],y=node[2];

            if(x==m-1 && y==n-1) return cost;

            for(auto dir:dirs){
                int new_x=x+dir[0],new_y=y+dir[1];
                if(isValid(new_x,new_y)){
                    int path_cost=findDir(x,y,dir[0],dir[1],grid);
                    if(path_cost+cost<costs[new_x][new_y]){
                        costs[new_x][new_y]=path_cost+cost;
                        if(path_cost==0) dq.push_front({cost,new_x,new_y});
                        else dq.push_back({cost+1,new_x,new_y});
                    }
                } 
            }
        }

        return -1;

    }
};