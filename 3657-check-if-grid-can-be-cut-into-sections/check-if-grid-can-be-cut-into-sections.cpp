class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(rectangles, 0, 2, n) || checkCuts(rectangles, 1, 3, n);
    }

private:
    bool checkCuts(vector<vector<int>>& rectangles, int start, int end, int n) {
        sort(rectangles.begin(), rectangles.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[start] < b[start];
        });

        int lines = 0, j = 0;
        for (int i = 0; i < rectangles.size() && j < n; i++) {
            if (rectangles[i][start] >= j) {
                lines++;
                j = rectangles[i][end];
            } else if (rectangles[i][end] > j) {
                j = rectangles[i][end];
            }
        }
        
        return lines >= 3;
    }
};
