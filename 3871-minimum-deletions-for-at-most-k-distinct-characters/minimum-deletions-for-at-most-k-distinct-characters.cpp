class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int>freq(26,0);
        for(char& ch:s){
            freq[ch-'a']++;
        }
        sort(begin(freq),end(freq));
        int i=0;
        while(freq[i]==0){
            i++;
        }
        int deletion=0;
        while(26-i>k){
            deletion+=freq[i];
            i++;
        }

        return deletion;
    }
};