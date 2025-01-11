class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert the 2D board to a single string representation
        string start = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }
        // Define the target string we want to reach
        string target = "123450";

        // Define a map of valid movements for each index in the 1D string
        // These represent the indices we can swap with the current index of '0'
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {3, 1, 5};
        mp[5] = {4, 2};

        // BFS queue to explore all possible board states
        queue<string> q;
        q.push(start);

        // Set to keep track of visited states and avoid revisiting
        unordered_set<string> visited;
        visited.insert(start);

        int level = 0; // Track the number of moves (BFS levels)

        // Perform BFS to find the shortest path to the target state
        while (!q.empty()) {
            int n = q.size(); // Number of states at the current BFS level
            while (n--) {
                string curr = q.front();
                q.pop();

                // If we reached the target state, return the number of moves
                if (curr == target) {
                    return level;
                }

                // Find the index of '0' in the current state
                int idxof0 = curr.find('0');

                // Generate all possible next states by swapping '0' with valid neighbors
                for (int swapIdx : mp[idxof0]) {
                    string newState = curr;
                    swap(newState[swapIdx], newState[idxof0]); // Swap positions

                    // If the new state hasn't been visited, add it to the queue
                    if (visited.find(newState) == visited.end()) {
                        visited.insert(newState);
                        q.push(newState);
                    }
                }
            }
            level++; // Increment the level (number of moves)
        }

        // If we exhaust all states and don't find the target, return -1
        return -1;
    }
};
