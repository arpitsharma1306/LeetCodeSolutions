class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int count=0;
        for(string& word:words){
            if(pref.size()<=word.size() && word.compare(0,pref.size(), pref)==0){
                count++;
            }
        }

        return count;
    }
};