class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1;
        int i=1;
        while(i<word.size()){
            int len = 1;
            while(word[i]==word[i-1]){
                i++;
                len++;
            }
            cnt += (len-1);
            i++;
        }

        return cnt;
    }
};