class Solution {
public:
    bool isPrime(int n){
        if(n<2) return false;
        if(n==2 || n==3) return true;
        if(n%2==0 || n%3==0) return false;

        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0) return false;
        }

        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes;
        for(int i=left;i<=right;i++){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }
        if(primes.size()<2){
            return {-1,-1};
        }
        if(primes.size()==2){
            return {primes[0],primes[1]};
        }

        vector<int>res(2);
        res[0]=primes[0];
        res[1]=primes[1];
        int diff=res[1]-res[0];
        for(int i=2;i<primes.size();i++){
            if(diff>primes[i]-primes[i-1]){
                res[0]=primes[i-1];
                res[1]=primes[i];
                diff=res[1]-res[0];
            }
        }

        return res;
    }
};