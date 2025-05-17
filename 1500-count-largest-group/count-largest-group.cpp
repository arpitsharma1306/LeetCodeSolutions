class Solution {
public:
    int digit_sum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }

        return sum;
    }
    int countLargestGroup(int n) {
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            int sum=digit_sum(i);
            mp[sum]++;
        }

        int maxFreq=0;
        for(auto& it:mp){
            if(maxFreq<it.second){
                maxFreq=it.second;
            }
        }
        int ans=0;
        for(auto &it:mp){
            if(it.second==maxFreq) ans++;
        }

        return ans;
    }
};