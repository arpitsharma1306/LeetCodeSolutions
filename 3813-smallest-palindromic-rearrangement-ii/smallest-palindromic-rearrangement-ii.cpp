class Solution {
public:
    int ncr(int n,int r,int limit){
        if(r>n-r) r=n-r;
        long long res = 1;
        for(int i=1;i<=r;i++){
            res *= (n-i+1);
            res /=i;
            if(res>limit) return limit+1;
        }
        return res;
    }
    int compPerm(vector<int>&freq,int limit){
        int total = accumulate(freq.begin(),freq.end(),0);
        long long res = 1;
        for(int i=0;i<26;i++){
            int choices = ncr(total,freq[i],limit);
            if(choices==limit+1) return limit+1;
            res *= choices;
            if(res>=limit+1) return limit+1;
            total-=freq[i];
        }

        return res;
    }
    string smallestPalindrome(string s, int k) {
        int n=s.size();
        vector<int>freq(26,0);
        char middle='?';

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]%2){
                middle = char(i+'a');
            }
            freq[i]/=2;
        }

        if(compPerm(freq,k)<k) return "";
        string ans="";
        for(int i=0;i<n/2;i++){
            for(int i=0;i<26;i++){
                if(freq[i]==0) continue;
                freq[i]--;
                int perm = compPerm(freq,k);
                if(perm>=k){
                    ans+=(i+'a');
                    break;
                }else{
                    k-=perm;
                    freq[i]++;
                }
            }
        }

        if(middle!='?') ans+=middle;
        for(int i=n/2-1;i>=0;i--) ans+=ans[i];

        return ans;

    }
};