class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();
        vector<long long>prefix(n);
        vector<long long>suffix(n);
        prefix[0]=(s[0]=='L');
        for(int i=1;i<s.size();i++){
            prefix[i]=prefix[i-1]+(s[i]=='L');
        }
        suffix[n-1]=(s[n-1]=='T');
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+(s[i]=='T');
        }

        //taken L at first
        long long maxi = 0;
        long long sum = 0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='C'){
                sum+= ((prefix[i]+1)*suffix[i]);
            }
        }
        maxi = sum;
        //taken T at last
        sum=0;
        for(int i=1;i<n;i++){
            if(s[i]=='C'){
                sum += (prefix[i]*(suffix[i]+1));
            }
        }
        maxi=max(maxi,sum);
        //best place to take C
        sum=0;
        long long maxMul = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='C'){
                sum+= (prefix[i]*suffix[i]);
            }
            maxMul= max(maxMul,prefix[i]*suffix[i]);
        }
        sum+=maxMul;
        maxi = max(maxi,sum);

        return maxi;

    }
};