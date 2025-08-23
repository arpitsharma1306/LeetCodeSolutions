class Solution {
public:

    int minimumArea(int startRow,int endRow,int startCol,int endCol,vector<vector<int>>&grid){
        int m=grid.size(), n=grid[0].size();
        int row1 =0, row2=m-1, col1=0, col2=n-1;
        for(int i=startRow;i<endRow;i++){
            for(int j=startCol;j<endCol;j++){
                if(grid[i][j]==1){
                    row1 = max(row1,i);
                    row2 = min(row2,i);
                    col1 = max(col1,j);
                    col2 = min(col2,j);
                }
            }
        }
        if(row1-row2<0 || col1-col2<0) return 0;

        return (row1-row2+1)*(col1-col2+1);
    }

    int solve(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int result = INT_MAX;

        for(int rowSplit = 1; rowSplit<m; rowSplit++){
            for(int colSplit = 1; colSplit<n; colSplit++){
                int top = minimumArea(0,rowSplit,0,n,grid);
                int bottomLeft = minimumArea(rowSplit,m,0,colSplit,grid);
                int bottomRight = minimumArea(rowSplit,m,colSplit,n,grid);

                result = min(result,top+bottomLeft+bottomRight);

                int topLeft = minimumArea(0,rowSplit,0,colSplit,grid);
                int topRight = minimumArea(0,rowSplit,colSplit,n,grid);
                int bottom = minimumArea(rowSplit,m,0,n,grid);

                result = min(result,topLeft+topRight+bottom);
            }
        }

        for(int split1 = 0;split1<m;split1++){
            for(int split2 = split1+1; split2<m; split2++){
                int top = minimumArea(0,split1,0,n,grid);
                int middle = minimumArea(split1,split2,0,n,grid);
                int bottom = minimumArea(split2,m,0,n,grid);

                result = min(result,top+middle+bottom);
            }
        }

        return result;
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid){
        int m = grid.size(), n=grid[0].size();

        vector<vector<int>>newGrid(n,vector<int>(m));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                newGrid[j][m-i-1] = grid[i][j];
            }
        }

        return newGrid;
    }    

    int minimumSum(vector<vector<int>>& grid) {
        int result = solve(grid);
        vector<vector<int>> newGrid = rotateGrid(grid);
        result = min(result,solve(newGrid));

        return result;
    }
};