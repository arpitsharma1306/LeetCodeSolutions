class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways=0;
        for(int i=0;i<=min(limit,n);i++){
            int remain = n-i; 
            if(2*limit<remain) continue;
            if(limit>=remain){
                ways+=(remain+1);
                continue;
            }
            ways+=((2*limit)-remain+1);
        }

        return ways;
    }
};