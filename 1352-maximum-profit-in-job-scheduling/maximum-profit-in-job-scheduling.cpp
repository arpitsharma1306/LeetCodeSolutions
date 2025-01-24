class Solution {
public:
    int n;
    vector<int>t;
    int getNexti(vector<vector<int>>&arr,int i,int end){
        int r=n-1;
        int l=i;
        int result=n+1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid][0]>=end){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return result;
    }
    int solve(vector<vector<int>>&arr,int i){
        if(i>=n) return 0;

        if(t[i]!=-1) return t[i];

        int next = getNexti(arr,i+1,arr[i][1]);
        int taken = arr[i][2] + solve(arr,next);
        int skip = solve(arr,i+1);

        return t[i] = max(taken,skip);

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=profit.size();
        t.resize(n,-1);
        vector<vector<int>>arr(n,vector<int>(3,0));

        for(int i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }

        sort(begin(arr),end(arr));

        return solve(arr,0);
    }
};