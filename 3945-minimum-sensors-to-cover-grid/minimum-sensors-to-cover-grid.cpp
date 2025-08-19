class Solution {
public:
    int minSensors(int n, int m, int k) {
        int s = 2*k + 1;
        long long rows = ceil((double)n/s);
        long long cols = ceil((double)m/s);
        return (int)(rows*cols);
    }
};