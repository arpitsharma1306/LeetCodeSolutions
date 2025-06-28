class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') ans++;
        }
        int zeroes = ans;
        long long num = 0;
        int place = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                zeroes--;
                place++;
                if(place>=32) place--;
                continue;
            }           
            num = num + pow(2,place);
            place++;
            if(num<=k){
                ans = max(ans,place+zeroes);
            }else{
                place = 1;
                num = 0;
            }     
        }

        return ans;
    }
};