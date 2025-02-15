class Solution {
public:
    bool solve(int sq,int currsum,int target){
        if(sq==0){
            return currsum==target;
        }

        return solve(sq/10,currsum+sq%10,target) || solve(sq/100,currsum+sq%100,target) || solve(sq/1000,currsum+sq%1000,target) || solve(sq/10000,currsum+sq%10000,target);
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            if(solve(sq,0,i)){
                sum+=sq;
            }
        }

        return sum;
    }
};