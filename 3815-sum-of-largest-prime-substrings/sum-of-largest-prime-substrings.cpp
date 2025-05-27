class Solution {
public:
    bool isPrime(long long n){
        if(n<=1) return false;
        if(n==2 || n==3) return true;
        if(n%2==0 || n%3==0) return false;

        for(long long i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0) return false;
        }

        return true;
    }

    long long sumOfLargestPrimes(string s) {
        vector<long long>primes;
        unordered_set<long long>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                string number = s.substr(i,j-i);
                long long num = stoll(number);
                if(st.find(num)!=st.end()) continue;

                if(isPrime(num)){
                    primes.push_back(num);
                    st.insert(num);
                }
            }
        }

        sort(rbegin(primes),rend(primes));
        if(primes.size()<=3){
            long long sum = accumulate(primes.begin(),primes.end(),0LL);
            return sum;
        }

        return primes[0]+primes[1]+primes[2];
    }
};