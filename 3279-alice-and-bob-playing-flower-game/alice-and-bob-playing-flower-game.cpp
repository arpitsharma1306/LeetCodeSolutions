class Solution {
public:
    long long flowerGame(int n, int m) {
        long long cnt = 0;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                cnt +=(long long)(m+1)/2;
            }else{
                cnt +=(long long)(m/2);
            }
        }

        return cnt;
    }
};