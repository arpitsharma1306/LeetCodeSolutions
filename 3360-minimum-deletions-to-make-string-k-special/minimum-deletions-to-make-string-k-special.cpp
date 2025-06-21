class Solution {
public:
    int solve(vector<int>&freq,int k,int minf){
        int erased = 0;

        for(int &x:freq){
            erased += (x<minf)?x:0;
            erased += (x>minf+k)?x-minf-k:0;
        }

        return erased;
    }
    int minimumDeletions(string word, int k) {
        vector<int>freq(26,0);
        for(char& ch:word){
            freq[ch-'a']++;
        }
        
        sort(freq.rbegin(),freq.rend());
        int deleted=accumulate(freq.begin(),freq.end(),0);

        while(freq.back()==0) freq.pop_back();

        for(int f=freq.back();f<=freq[0];f++){
            deleted = min(deleted,solve(freq,k,f));
        }

        return deleted;
    }
};