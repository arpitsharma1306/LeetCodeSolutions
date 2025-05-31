class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // x_to_ys[i] stores all y-values of buildings that share the same x = i
        vector<vector<int>> x_to_ys(n + 1);
        // y_to_xs[j] stores all x-values of buildings that share the same y = j
        vector<vector<int>> y_to_xs(n + 1);

        // Populate mappings
        for (auto& building : buildings) {
            int x = building[0], y = building[1];
            x_to_ys[x].push_back(y);
            y_to_xs[y].push_back(x);
        }

        // Sort each list to easily find min and max
        for (auto& ys : x_to_ys) {
            sort(ys.begin(), ys.end());
        }
        for (auto& xs : y_to_xs) {
            sort(xs.begin(), xs.end());
        }

        int coveredCount = 0;

        for (auto& building : buildings) {
            int x = building[0], y = building[1];

            // Need at least three points along the same x or y to form a boundary
            if (x_to_ys[x].size() < 3 || y_to_xs[y].size() < 3) continue;

            int minY = x_to_ys[x].front();
            int maxY = x_to_ys[x].back();
            int minX = y_to_xs[y].front();
            int maxX = y_to_xs[y].back();

            // The building is covered if it lies strictly inside a rectangle formed by other buildings
            if (minX < x && x < maxX && minY < y && y < maxY) {
                coveredCount++;
            }
        }

        return coveredCount;
    }
};
