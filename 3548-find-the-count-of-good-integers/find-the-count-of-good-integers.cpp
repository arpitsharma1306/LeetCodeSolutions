class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string>st;
        int d = (n+1)/2;
        int start = pow(10,d-1);
        int end   = pow(10,d)-1;

        for(int num=start;num<=end;num++){
            string leftHalf = to_string(num);
            string full = "";
            if(n%2==0){
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(),rightHalf.end());
                full = leftHalf + rightHalf;
            }else{
                string rightHalf = leftHalf.substr(0,d-1);
                reverse(rightHalf.begin(),rightHalf.end());
                full = leftHalf + rightHalf;
            }
            long long number = stoll(full);
            if(number%k==0){
                sort(full.begin(),full.end());
                st.insert(full);
            }
        }
        long long result = 0;
        vector<long long>factorial(11,1);
        for(int i=2;i<11;i++){
            factorial[i] = factorial[i-1] * i;
        }
        for(const string &s:st){
            vector<int>count(10,0);
            for(const char & ch:s){
                count[ch-'0']++;
            }

            int zeroCount = count[0];
            int nonzeroCount = n - zeroCount;
            long long perm = nonzeroCount * factorial[n-1];
            for(int i=0;i<10;i++){
                perm/=factorial[count[i]];
            }
            result += perm;
        }

        return result;
    }
};