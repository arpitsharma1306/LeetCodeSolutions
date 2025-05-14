class Solution {
public:
    #define MOD 1000000007 
    int lengthAfterTransformations(string s, int t) {
        vector<int>nums(26,0);
        for(char &ch:s){
            nums[ch-'a']++;
        }

        while(t--){
            vector<int>cnt(26,0);
            for(int i=0;i<26;i++){
                if(i==25 && nums[i]>0){
                    cnt[0] = (cnt[0]+nums[i])%MOD;
                    cnt[1] = (cnt[1]+nums[i])%MOD;
                }
                else{
                    if(i<25){
                        cnt[i+1] = (cnt[i+1]+nums[i])%MOD;
                    }
                }
                
            }

            for (int i = 0; i < 26; i++) {
    nums[i] = cnt[i];
}
        }

        int ans=0;
        for(int i=0;i<26;i++){
            ans = (ans+nums[i])%MOD;

        } 

        return ans;
    }
};