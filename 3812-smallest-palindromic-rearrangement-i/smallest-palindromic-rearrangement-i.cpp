class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<26;i++){
            int cnt=freq[i]/2;
            while(cnt--){
                ans+=('a'+i);
            }
        }
        for(int i=0;i<26;i++){
            int odd = freq[i]%2;
            if(odd==1){
                ans+=('a'+i);
            }
        }

        for(int i=25;i>=0;i--){
            int cnt=freq[i]/2;
            while(cnt--){
                ans+=('a'+i);
            }
        }

        return ans;
    }
};