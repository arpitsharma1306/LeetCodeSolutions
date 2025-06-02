class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0, right=0, extra=0;

        for(char& s:moves){
            if(s=='L') left++;
            else if(s=='R') right++;
            else extra++;
        }

        return abs(left-right)+extra;
    }
};