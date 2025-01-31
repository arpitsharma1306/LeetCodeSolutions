class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    // DFS to calculate the size of each island and mark them with an ID
    int dfs(vector<vector<int>>& grid, int i, int j, int island_id, unordered_map<int, int>& islandSize) {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return 0;

        grid[i][j] = island_id;  // Mark with island_id
        int size = 1;
        for (auto dir : dirs) {
            size += dfs(grid, i + dir[0], j + dir[1], island_id, islandSize);
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> islandSize;  // Map island_id → island_size
        int island_id = 2;  // Start from 2 (1 is used for land)
        int maxIsland = 0;

        // Step 1: Mark islands and calculate their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    islandSize[island_id] = dfs(grid, i, j, island_id, islandSize);
                    maxIsland = max(maxIsland, islandSize[island_id]);
                    island_id++;
                }
            }
        }

        // Step 2: Try converting each `0` to `1` and find the maximum connected island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seenIslands;
                    int newSize = 1;

                    // Check all 4 neighbors
                    for (auto dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1) {
                            seenIslands.insert(grid[x][y]); // Collect unique island IDs
                        }
                    }

                    // Sum up the sizes of unique neighboring islands
                    for (int id : seenIslands) {
                        newSize += islandSize[id];
                    }

                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};
