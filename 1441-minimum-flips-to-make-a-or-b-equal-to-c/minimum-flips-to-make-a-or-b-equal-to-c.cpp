//modulo operation -->
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a > 0 || b > 0 || c > 0) {
            if(c%2 == 0) {
                flips += a%2 + b%2;
            }
            else{
                if(a%2 == 0 && b%2 == 0) flips += 1;
            }
            a /= 2;
            b /= 2;
            c /= 2;
        }
        return flips;
    }
};