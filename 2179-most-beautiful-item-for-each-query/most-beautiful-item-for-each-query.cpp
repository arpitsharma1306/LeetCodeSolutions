class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {

        sort(items.begin(), items.end(),
             [](const std::vector<int>& a, const std::vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<int> answer;

        for (int i = 0; i < queries.size(); i++) {
            int j = items.size() - 1;
            while (j >0 && items[j][0] > queries[i]) {
                j--;
            }
            if (items[j][0] <= queries[i]) {
                answer.push_back(items[j][1]);
            } else {
                answer.push_back(0);
            }
        }

        return answer;
    }
};