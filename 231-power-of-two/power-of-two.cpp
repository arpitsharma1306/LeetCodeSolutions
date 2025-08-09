class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        n = abs(n);
        while(n>0){
            if(n==1) return true;
            if(n%2!=0) return false;
            n/=2;
        }

        return true;
    }
};