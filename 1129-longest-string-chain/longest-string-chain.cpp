class Solution {
public:
    int n;
    int t[1001][1001];
    bool isPredecessor(const string& str1, const string& str2){
        if (str2.length() != str1.length() + 1) return false;
        int i = 0, j = 0; // Pointers for str1 and str2
        bool mismatchFound = false;
        while (i < str1.length() && j < str2.length()) {
            if (str1[i] == str2[j]) {
                // Characters match, move both pointers
                i++;
                j++;
            } else {
                if (mismatchFound) {
                    // More than one mismatch
                    return false;
                }
                mismatchFound = true;
                j++; // Skip the extra character in str2
            }
        }
        return true;
    }

    int solve(vector<string>&words,int pre_idx,int curr_idx){
        if(curr_idx>=n) return 0;

        if(pre_idx!=-1 && t[pre_idx][curr_idx]!=-1){
            return t[pre_idx][curr_idx];
        }

        int taken=0,skip=0;

        if(pre_idx==-1 || isPredecessor(words[pre_idx],words[curr_idx])){
            taken = solve(words,curr_idx,curr_idx+1)+1;
        }
        skip = solve(words,pre_idx,curr_idx+1);

        if(pre_idx!=-1) t[pre_idx][curr_idx] = max(taken,skip);

        return max(taken,skip);
    }
    int longestStrChain(vector<string>& words) {
        n=words.size();
        memset(t,-1,sizeof(t));
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
        });

        return solve(words,-1,0);
    }
};