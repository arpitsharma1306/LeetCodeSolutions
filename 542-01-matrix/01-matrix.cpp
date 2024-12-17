class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        vector<vector<int>>dir{{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>>q;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }    
            }
        }

        while(!q.empty()){
            auto cell=q.front();
            q.pop();
            int i=cell.first;
            int j=cell.second;

            for(auto &it:dir){
                int x=i+it[0];
                int y=j+it[1];

                if(x>=0 && x<m && y>=0 && y<n && ans[x][y]==-1){
                    ans[x][y]=ans[i][j]+1;
                    q.push({x,y});
                }
            }
        }

        return ans;
    }
};