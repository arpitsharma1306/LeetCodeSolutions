class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>>dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        result[0][0]=0;
        pq.push({0,{0,0}}); //{weight,{i,j}}

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int d=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;

            for(auto& dir:dirs){
                int x=i+dir[0],y=j+dir[1];
                if(x<0 || x>m-1 || y<0 || y>n-1){
                    continue;
                }
                if(d+grid[x][y]<result[x][y]){
                    result[x][y]=d+grid[x][y];
                    pq.push({d+grid[x][y],{x,y}});
                }
            }
        }

        return result[m-1][n-1];

    }
};