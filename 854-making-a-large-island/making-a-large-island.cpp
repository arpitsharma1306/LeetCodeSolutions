class Solution {
public:
    int n;
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    // DFS to find the size of an island and mark it with a unique ID
    int DFS(vector<vector<int>>& grid, int id, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) {
            return 0;
        }
        
        grid[i][j] = id;  // Mark cell with the island ID
        int size = 1;
        
        for (auto& dir : dirs) {
            size += DFS(grid, id, i + dir[0], j + dir[1]);
        }
        
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize;  // Maps island ID -> its size
        int id = 2;  // Start ID from 2 to avoid confusion with 0 and 1
        int maxArea = 0;
        bool hasZero = false;  // Check if there's any zero in the grid

        // Step 1: Identify all islands and mark them
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    islandSize[id] = DFS(grid, id, i, j);
                    maxArea = max(maxArea, islandSize[id]);
                    id++;
                } else if (grid[i][j] == 0) {
                    hasZero = true;
                }
            }
        }

        // If the grid is full of 1s, return the max possible area (n * n)
        if (!hasZero) return n * n;

        // Step 2: Try converting each `0` to `1` and find the largest connected island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborIslands;
                    for (auto& dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1) {
                            neighborIslands.insert(grid[x][y]);
                        }
                    }

                    int newSize = 1; // New island size after flipping (count the `0` itself)
                    for (int islandId : neighborIslands) {
                        newSize += islandSize[islandId];
                    }

                    maxArea = max(maxArea, newSize);
                }
            }
        }

        return maxArea;
    }
};
