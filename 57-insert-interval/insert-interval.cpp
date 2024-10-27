class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool added = false;
        for (auto interval : intervals) {
            if (interval[1] < newInterval[0]) { // curr is to the left, just add it
                res.push_back(interval);
            } else if (interval[0] > newInterval[1]) {  // curr is to the right, add new interval and add interval
                if (!added) { 
                    res.push_back(newInterval);
                    added = true;
                }
                res.push_back(interval);
            } else { // curr and new interval overlap, merge
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        if (!added) { 
            res.push_back(newInterval);
        }
        return res;
    }
};