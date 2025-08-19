class Solution {
public:
    int minSensors(int n, int m, int k) {
        int s = 2*k + 1;
        long long rows = (n+s-1)/s;
        long long cols = (m+s-1)/s;
        return (int)(rows*cols);
    }
};