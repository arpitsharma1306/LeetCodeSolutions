class Solution {
public:
    int commonPrefixLength(const string& s1, const string& s2) {
        int len = min(s1.size(), s2.size());
        int i = 0;
        while (i < len && s1[i] == s2[i]) {
            i++;
        }
        return i;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        vector<int>res(n,0);
        if(n<3) return res;
        vector<int>deletedCommon(n,0);
        vector<int>left(n,0);
        for(int i=1;i<n-1;i++){
            deletedCommon[i]=commonPrefixLength(words[i-1],words[i+1]);
            if(i==1){
                continue;
            }
            left[i]=max(left[i-1],commonPrefixLength(words[i-1],words[i-2]));
        }
        left[n-1] = max(left[n-2],commonPrefixLength(words[n-2],words[n-3]));

        int maxi_right = 0;
        for(int i=n-3;i>=0;i--){
            maxi_right = max(maxi_right,commonPrefixLength(words[i+1],words[i+2]));
            left[i] = max({left[i],maxi_right,deletedCommon[i]});
        }

        left[0]=max(left[0],deletedCommon[0]);
        left[1]=max(left[1],deletedCommon[1]);
        left[n-2]=max(left[n-2],deletedCommon[n-2]);
        left[n-1]=max(left[n-1],deletedCommon[n-1]);

        return left;
    }
};