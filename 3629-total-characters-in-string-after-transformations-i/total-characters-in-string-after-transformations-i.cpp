class Solution {
public:
    #define mod 1000000007 
    int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
    int lengthAfterTransformations(string s, int t) {
        vector<int>nums(26,0);
        for(char &ch:s){
            nums[ch-'a']++;
        }

        while(t--){
            vector<int>cnt(26,0);
            for(int i=0;i<26;i++){
                if(i==25 && nums[i]>0){
                    cnt[0] = mod_add(cnt[0],nums[i]);
                    cnt[1] = mod_add(cnt[1],nums[i]);
                }else{
                    if(i<25){
                        cnt[i+1] = mod_add(cnt[i+1],nums[i]);
                    }
                    
                }
                
            }

            for (int i = 0; i < 26; i++) {
    nums[i] = cnt[i];
}
        }

        int ans=0;
        for(int i=0;i<26;i++){
            ans = mod_add(ans,nums[i]);
            ans=ans%mod;
        } 

        return ans;
    }
};