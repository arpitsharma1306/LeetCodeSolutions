class Solution {
public:
    int n;
    vector<vector<int>>dirs = {{0,1},{0,-1},{-1,0},{1,0}};
    int DFS(vector<vector<int>>& grid,int id,int i,int j){
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=1){
            return 0;
        }
        int count = 1;
        grid[i][j]=id;
        for(auto dir:dirs){
            int i_=i+dir[0], j_=j+dir[1];
            count += DFS(grid,id,i_,j_);
        }

        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        unordered_map<int,int>mp;
        int ids=2;
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    mp[ids]=DFS(grid,ids,i,j);
                    maxArea=max(maxArea,mp[ids]);
                    ids++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
                    for(auto dir:dirs){
                        int i_=i+dir[0], j_=j+dir[1];
                        if(i_>=0 && j_>=0 && i_<n && j_<n && grid[i_][j_]!=0){
                            st.insert(grid[i_][j_]);
                        }
                    }
                    int islandArea=1;
                    for(auto id:st){
                        islandArea+=mp[id];
                    }
                    maxArea=max(maxArea,islandArea);
                }
            }
        }

        return maxArea;

    }
};