class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(words[j].size() >= words[i].size() && words[j].rfind(words[i],0)==0 && words[j].compare(words[j].size() - words[i].size(), words[i].size(), words[i]) == 0){
                    count++;
                }
            }
        }

        return count;
    }
};