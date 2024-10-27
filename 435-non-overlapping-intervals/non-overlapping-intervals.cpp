class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 0, j = 1, count = 0;
        sort(begin(intervals), end(intervals));

        while (j < n) {
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            int ns = intervals[j][0];
            int ne = intervals[j][1];

            if (ce <= ns) { // not overlapping
                i = j;
                j++;
            } else if (ce <= ne) { // overlapping with second one having end
                                   // more value usko delete kar diya i.e j
                                   // increased i wahi par hi
                j++;
                count++;
            } else if (ce > ne) { // overlapping with first one have bigger end
                                  // value. so i ko j ke equal and j++
                i = j;
                j++;
                count++;
            }
        }

        return count;
    }
};