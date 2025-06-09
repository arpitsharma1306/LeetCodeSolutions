class Solution {
public:
    int check(long a,long b,long n){
        int gap = 0;
        while(a<=n){
            gap += min(n+1,b) - a;
            a *= 10;
            b *= 10;
        }

        return gap;
    }
    int findKthNumber(int n, int k) {
        long num=1;
        for(int i=1;i<k;){
            int gap = check(num,num+1,n);
            if(i+gap<=k){
                i += gap;
                num++;
            }else{
                i++;
                num *= 10;
            }
        }

        return num;
    }
};