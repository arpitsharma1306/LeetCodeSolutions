class Solution {
public:
    int m,n;
    const int mod = 1e9+7;
    vector<vector<vector<long long>>> dp;

    bool check(int x,int y){
        return x>=0 && y>=0 && x<m && y<n;
    }

    long long solve(int x,int y,int down,vector<vector<int>>& grid){
        if (x==m-1 && y==n-1) return 1;
        
        if (dp[x][y][down+1] != -1) return dp[x][y][down+1];

        if (grid[x][y]==1) {
            if (down) {
                if (check(x,y+1))
                    return dp[x][y][down+1] = solve(x,y+1,0,grid) % mod;
                return dp[x][y][down+1] = 0;
            } else {
                if (check(x+1,y))
                    return dp[x][y][down+1] = solve(x+1,y,1,grid) % mod;
                return dp[x][y][down+1] = 0;
            }
        }

        long long cnt = 0;
        // move down
        if (check(x+1,y)) cnt = (cnt + solve(x+1,y,1,grid)) % mod;
        // move right
        if (check(x,y+1)) cnt = (cnt + solve(x,y+1,0,grid)) % mod;

        return dp[x][y][down+1] = cnt;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.assign(m, vector<vector<long long>>(n, vector<long long>(3,-1)));
        return solve(0,0,-1,grid);
    }
};
