class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int j = n - 1;

        // Step 1: Find the rightmost index where the array is no longer non-decreasing
        while (j > 0 && arr[j] >= arr[j - 1]) {
            j--; // Move `j` left until the non-decreasing property is broken
        }

        // If the entire array is already sorted, no need to remove any subarray
        if (j == 0) return 0;

        int result = j; // Initially, consider removing the entire left part up to index `j`
        int i = 0;

        // Step 2: Iterate from the left to find the minimum length of the subarray to remove
        while (i < j && (i == 0 || arr[i] >= arr[i - 1])) {
            // Ensure `j` points to a valid position where arr[j] >= arr[i]
            while (j < n && arr[j] < arr[i]) {
                j++; // Move `j` right to maintain the non-decreasing condition
            }

            // Update the result with the minimum length of the subarray to remove
            result = min(result, j - i - 1);

            i++; // Move `i` right to check for other possibilities
        }

        return result; // Return the minimum length of the subarray to remove
    }
};
