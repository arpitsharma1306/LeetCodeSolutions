class Solution {
public:
    bool isPowerOfFour(int n) {
        long long i=1;
        if(n<1) return false;
        while(i<=n){
            if(i==n) return true;
            i*=4;
        }

        return false;
    }
};