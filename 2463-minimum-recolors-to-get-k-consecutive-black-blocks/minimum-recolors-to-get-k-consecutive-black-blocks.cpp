class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int i=0;
        int whites=0;
        for(;i<k;i++){
            if(blocks[i]=='W') whites++;
        }
        int mini=whites;
        if(n==k) return mini;

        for(;i<n;i++){
            if(blocks[i-k]=='W') whites--;
            if(blocks[i]=='W') whites++;
            mini=min(mini,whites);
        }

        return mini;
    }
};