class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        //probabity vector bna lenge
        vector<double>P(n+1,0.0);
        //start 0 se hoga to uski prob 1 hui 
        P[0] = 1;
        // same but if k=0 then 0 kar denge, game start hi nhi hua
        double currProb = (k==0)?0:1;
        for(int i=1;i<=n;i++){
            P[i] = currProb/maxPts;

            if(i<k) currProb+=P[i];

            if(i-maxPts>=0 && i-maxPts<k) currProb-=P[i-maxPts];
        }

        return accumulate(P.begin()+k,P.end(),0.0);
    }
};