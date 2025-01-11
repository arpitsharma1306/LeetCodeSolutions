class Solution {
public:
    bool canConstruct(string s, int k) {
        int  n = s.size();
        if(k>n) return false;
        
        vector<int>freq(26,0);
        for(char &ch:s){
            freq[ch-'a']++;
        }

        int odd_times=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) odd_times++;
        }

        if(odd_times>k) return false;

        return true;
    }
};