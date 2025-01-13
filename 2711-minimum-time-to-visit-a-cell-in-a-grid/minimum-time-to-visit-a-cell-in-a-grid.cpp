class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Early exit if initial movement is impossible
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        // Directional movements: right, down, left, up
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Min-heap priority queue to process cells in order of minimum time
        using T = tuple<int, int, int>; // (time, i, j)
        priority_queue<T, vector<T>, greater<>> pq;
        pq.emplace(0, 0, 0);
        
        // Distance matrix to track minimum times to reach each cell
        vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
        dist[0][0] = 0;
        
        // Matrix to track visited cells
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        seen[0][0] = true;

        while (!pq.empty()) {
            auto [time, i, j] = pq.top();
            pq.pop();
            
            // Reached bottom-right cell
            if (i == m - 1 && j == n - 1) {
                return time;
            }
            
            // Explore four adjacent directions
            for (const auto& [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                
                // Validate next cell is within grid boundaries
                if (x >= 0 && x < m && y >= 0 && y < n && !seen[x][y]) {
                    int nextTime = time + 1;
                    
                    // Adjust time if arriving before cell's minimum time
                    if (nextTime < grid[x][y]) {
                        int waitTime = grid[x][y] - nextTime;
                        if (waitTime % 2 == 0) {
                            nextTime = grid[x][y];
                        } else {
                            nextTime = grid[x][y] + 1;
                        }
                    }
                    
                    // If a shorter path to (x, y) is found
                    if (nextTime < dist[x][y]) {
                        dist[x][y] = nextTime;
                        pq.emplace(nextTime, x, y);
                        seen[x][y] = true;
                    }
                }
            }
        }
        
        // If the bottom-right cell is unreachable, return -1
        return -1;
    }
};
