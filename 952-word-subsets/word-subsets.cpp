class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq(26,0);
        for(string& str:words2){
            vector<int>freqstr(26,0);
            for(char &ch:str){
                freqstr[ch-'a']++;
                if(freqstr[ch-'a']>freq[ch-'a']){
                    freq[ch-'a']=freqstr[ch-'a'];
                }
            }  
        }

        vector<string>answer;

        for(string& str:words1){
            vector<int> stringFreq(26, 0);
            for (char ch : str) {
                stringFreq[ch - 'a']++;
            }
            bool flag=true;
            for (int i = 0; i < 26; ++i) {
                if (stringFreq[i] < freq[i]) {
                    flag=false;
                }
            }
            if(flag) answer.push_back(str);
        }

        return answer;
    }
};