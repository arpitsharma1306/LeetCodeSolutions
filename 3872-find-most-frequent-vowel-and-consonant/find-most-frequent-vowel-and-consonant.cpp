class Solution {
public:
    void findmaxVowel(int &maxVowel,vector<int>&freq){
        maxVowel=max(maxVowel,freq[0]);
        freq[0]=0;
        maxVowel=max(maxVowel,freq[4]);
        freq[4]=0;
        maxVowel=max(maxVowel,freq[8]);
        freq[8]=0;
        maxVowel=max(maxVowel,freq[14]);
        freq[14]=0;
        maxVowel=max(maxVowel,freq[20]);
        freq[20]=0;
    }
    int maxFreqSum(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        int maxVowel=0;
        findmaxVowel(maxVowel,freq);
        sort(freq.rbegin(),freq.rend());

        return maxVowel+freq[0];
    }
};