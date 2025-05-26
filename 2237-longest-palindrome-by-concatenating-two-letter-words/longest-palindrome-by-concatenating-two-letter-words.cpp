class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        bool doubly=false;
        unordered_map<string,int>mp;
        for(auto& word:words){
            mp[word]++;
        }

        int cnt=0;

        for(auto& word:words){
            string finding = string() + word[1] + word[0];
            if(word[0]!=word[1] && mp.find(finding)!=mp.end()){
                int word_cnt = min(mp[finding],mp[word]);
                cnt += 4 * word_cnt;
                mp.erase(word);
                mp.erase(finding);
                continue;
            }else if(word[0]==word[1]){
                if(mp[word]%2==1){
                    doubly=true;
                }
                int word_cnt = mp[word]/2;
                cnt += 4* word_cnt;
                mp.erase(word);
                continue;
            }
            mp.erase(word);
        }
        if(doubly) cnt+=2;
        
        return cnt;
    }
};