class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        if(n<3) return n;

        vector<int>freq(26,0);

        for(char& ch:s){
            freq[ch-'a']++;
            if(freq[ch-'a']==3){
                freq[ch-'a']=1;
            }
        }

        int count=0;
        for(int i=0;i<26;i++){
            count+=freq[i];
        }

        return count;
    }
};