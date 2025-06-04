class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;

        int max_size = n - numFriends + 1;
        string ans = word.substr(0, max_size);

        for (int i = 1; i <= n - max_size; ++i) {
            string curr = word.substr(i, max_size);
            if (curr > ans) {
                ans = curr;
            }
        }

        for(int i = n-max_size+1;i<n;i++){
            string curr = word.substr(i,n-i);
            if(curr > ans) ans = curr; 
        }

        return ans;
    }
};
