class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxTillNow = values[0];
        int result=0;
        
        for(int j=1;j<n;j++){
            int x=maxTillNow;
            int y=values[j]-j;
            result=max(result,x+y);
            maxTillNow=max(maxTillNow,values[j]+j);
        }

        return result;
    }
};