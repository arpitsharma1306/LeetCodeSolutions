class Solution {
public:
    int N;
    vector<vector<vector<int>>>t;
    int solve(int i,int k,int currTime,vector<int>& position, vector<int>& time){
        if(i==N-1){
            if(k>0) return INT_MAX;
            return 0;
        }

        if(t[i][k][currTime]!=-1) return t[i][k][currTime];

        //skip
        int result = INT_MAX;
        int skip = solve(i+1,k,time[i+1],position,time);
        if(skip<INT_MAX){
            int dist = position[i+1]-position[i];
            result = min(result,dist*currTime+skip);
        }

        //taken
        if(k>0){
            int mergeTime=time[i+1];
            int mergePoints=0;
            for(int j=i+2;j<N && mergePoints<k;j++){
                mergePoints++;
                mergeTime+=time[j];
                int taken = solve(j,k-mergePoints,mergeTime,position,time);
                if(taken<INT_MAX){
                    int dist=position[j]-position[i];
                    result=min(result,dist*currTime+taken);
                }
            }
        }

        return t[i][k][currTime] = result;
        
    }

    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        N=n;
        int total_time=accumulate(time.begin(),time.end(),0);
        t.resize(N+1, vector<vector<int>>(k+1, vector<int>(total_time, -1)));
        return solve(0,k,time[0],position,time);
    }
};