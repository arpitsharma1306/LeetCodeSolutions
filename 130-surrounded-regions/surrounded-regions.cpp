class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(board[i][j]=='O'){
                        board[i][j]='S';
                        q.push({i,j});
                    }
                }
            }
        }

        vector<vector<int>>dir{{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){
            auto cell=q.front();
            q.pop();

            for(auto &it:dir){
                int x=cell.first+it[0];
                int y=cell.second+it[1];

                if(x>=0 && x<m-1 && y>=0 && y<n && board[x][y]=='O'){
                    q.push({x,y});
                    board[x][y]='S';
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='S') board[i][j]='O';  
            }
        }

    }
};