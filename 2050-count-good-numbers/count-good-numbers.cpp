class Solution {
public:
    const int M = 1e9+7;
    long long findPower(long long base,long long exp){
        if(exp==0){
            return 1;
        }

        long long half = findPower(base,exp/2);
        long long result = (half*half) % M;
        if(exp%2==1){
            result = (result*base) % M;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long) findPower(5,(n+1)/2) * findPower(4,n/2) % M;
    }
};