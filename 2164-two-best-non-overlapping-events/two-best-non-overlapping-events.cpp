class Solution {
public:
    int t[100001][3];
    int n;
    int finder(vector<vector<int>>& events,int start){
        int l=0;
        int r=n-1;
        int result=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][0]>start){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return result;
    }
    int solve(vector<vector<int>>& events,int i,int count){
        if(count==2 || i>=n){
            return 0;
        }

        if(t[i][count]!=-1){
            return t[i][count];
        }

        int nextValidIdx = finder(events,events[i][1]);

        int taken = events[i][2] + solve(events,nextValidIdx,count+1);
        int skip  = solve(events,i+1,count);

        return t[i][count] = max(taken,skip);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        memset(t,-1,sizeof(t));
        sort(begin(events),end(events));
        int count=0;
        return solve(events,0,count);
    }
};