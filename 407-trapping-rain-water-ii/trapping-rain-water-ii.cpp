class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        priority_queue<P,vector<P>,greater<P>>boundaryCell;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int row=0;row<m;row++){
            for(int col:{0,n-1}){
                boundaryCell.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }

        for(int row:{0,m-1}){
            for(int col=0;col<n;col++){
                boundaryCell.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }

        int water=0;
        while(!boundaryCell.empty()){
            P cell=boundaryCell.top();
            boundaryCell.pop();
            int height=cell.first;
            int i=cell.second.first, j=cell.second.second;

            for(auto dir:dirs){
                int i_=i+dir[0], j_=j+dir[1];
                if(i_>=0 && j_>=0 && i_<m && j_<n && !visited[i_][j_]){
                    water+=max(height-heightMap[i_][j_],0);
                    boundaryCell.push({max(height,heightMap[i_][j_]),{i_,j_}});
                    visited[i_][j_]=true;
                }
            }
        }

        return water;
    }
};