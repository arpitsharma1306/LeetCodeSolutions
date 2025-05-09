class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m=moveTime.size(), n=moveTime[0].size();

        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>reachedTime(m,vector<int>(n,INT_MAX));
        reachedTime[0][0] = 0;
        queue<pair<int,int>>q;
        q.push({0,0});

        while(!q.empty()){
            int x=q.front().first, y=q.front().second;
            q.pop();
            for(auto &dir:dirs){
                int x_=x+dir[0], y_=y+dir[1];
                if(x_>=0 && y_>=0 && x_<m && y_<n){
                    int time = reachedTime[x][y]<moveTime[x_][y_]?moveTime[x_][y_]+1:reachedTime[x][y]+1;
                    if(time<reachedTime[x_][y_]){
                        reachedTime[x_][y_]=time;
                        q.push({x_,y_});
                    }
                }
            }
        }

        return reachedTime[m-1][n-1];

    }
};