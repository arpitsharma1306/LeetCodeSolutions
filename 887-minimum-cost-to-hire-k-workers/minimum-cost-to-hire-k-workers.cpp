class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& minWage, int k) {
        int n = minWage.size();
        vector<pair<double, int>> ratio;

        // Calculate the wage-to-quality ratio for each worker and store it along with quality
        for (int i = 0; i < n; i++) {
            ratio.push_back({(double)minWage[i] / quality[i], quality[i]});
        }

        // Sort workers based on their wage-to-quality ratio in ascending order
        sort(begin(ratio), end(ratio));

        priority_queue<int, vector<int>> pq; // Max heap to store the highest qualities
        int sum_quality = 0;

        // Select the first 'k' workers with the smallest wage-to-quality ratios
        for (int i = 0; i < k; i++) {
            sum_quality += ratio[i].second; // Sum of selected workers' quality
            pq.push(ratio[i].second); // Push quality into the max heap
        }

        // Compute the minimum possible total cost
        double result = ratio[k - 1].first * sum_quality;

        // Iterate over the remaining workers
        for (int manager = k; manager < n; manager++) {
            double manager_ratio = ratio[manager].first;
            sum_quality += ratio[manager].second;
            pq.push(ratio[manager].second);

            // If more than 'k' workers are selected, remove the highest quality worker
            if (pq.size() > k) {
                sum_quality -= pq.top();
                pq.pop();
            }

            // Update the minimum cost
            result = min(result, ratio[manager].first * sum_quality);
        }

        return result;
    }
};
