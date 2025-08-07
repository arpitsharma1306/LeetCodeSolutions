class Solution {
public:
    int maxi1, maxi2,n;
    static constexpr int INF = numeric_limits<int>::max(); 
    int dfs(vector<vector<int>>& fruits,int i,int j,int moves,vector<vector<int>>& dp,vector<vector<int>>&dirs){
        
        int n=fruits.size();

        if(i==n-1 && j==n-1){
            return moves==0?0:INF;
        }
        if(moves==0 || i==j) return INF;
        if(dp[i][j]!=-1) return dp[i][j];
        long long max_fruit = -1;
        for(auto &dir:dirs){
            int i_=i+dir[0], j_=j+dir[1];
            if(i_>=0 && j_>=0 && i_<n && j_<n){
                int val = dfs(fruits,i_,j_,moves-1,dp,dirs);
                if(val!=INF) max_fruit = max(max_fruit,(long long)val);
            }
        }

        return dp[i][j] = max_fruit<0?INF:max_fruit+fruits[i][j];
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        //diagonal
        int first = 0;
        for(int i=0;i<n;i++) first+=fruits[i][i];

        // top to bottom
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<vector<int>>dirs = {{1,0},{1,-1},{1,1}};
        int second = dfs(fruits,0,n-1,n-1,dp,dirs);

        // left to right
        dirs = {{-1,1},{0,1},{1,1}};
        for(auto& row:dp) fill(row.begin(),row.end(),-1);
        int third = dfs(fruits,n-1,0,n-1,dp,dirs);

        return first+second+third;
    }
};