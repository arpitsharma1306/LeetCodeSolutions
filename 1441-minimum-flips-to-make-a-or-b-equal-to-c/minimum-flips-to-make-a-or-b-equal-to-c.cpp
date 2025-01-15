class Solution {
public:
    int minFlips(int a, int b, int c) {
        int xOR=(a|b)^c;
        int aND=xOR&(a&b);
        int count1=__builtin_popcount(xOR);
        int count2=__builtin_popcount(aND);
        return count1+count2;
    }
};