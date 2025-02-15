class Solution {
public:
    bool solve(int num,int tar){
        if(tar<0 || num<tar) return false;
        if(num==tar) return true;
        return solve(num/10,tar-num%10) || solve(num/100,tar-num%100) || solve(num/1000,tar-num%1000);
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            if(solve(sq,i)){
                sum+=sq;
            }
        }

        return sum;
    }
};