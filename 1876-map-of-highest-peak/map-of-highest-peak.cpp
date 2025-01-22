class Solution {
public:
    vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>result(m,vector<int>(n));
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<vector<int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({0,i,j});
                    visited[i][j]=true;
                }
            }
        }

        while(!q.empty()){
            int sz=q.size();
            for(int t=0;t<sz;t++){
                auto node=q.front();
                q.pop();
                int h=node[0],x=node[1],y=node[2];
                result[x][y]=h;
                for(auto dir:dirs){
                    int x_=x+dir[0],y_=y+dir[1];
                    if(x_>=0 && y_>=0 && x_<m && y_<n && !visited[x_][y_]){
                        q.push({h+1,x_,y_});
                        visited[x_][y_]=true;
                    }
                }
            }
        }

        return result;
    }
};