class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>gaps(n+1);
        gaps[0]=startTime[0];
        gaps[n]=eventTime-endTime[n-1];
        for(int i=1;i<n;i++){
            gaps[i]=startTime[i]-endTime[i-1];
        }

        int maxGap=0, windowSize=0;
        for(int i=0;i<=k && i<gaps.size();i++){
            maxGap+=gaps[i];
        }
        windowSize=maxGap;
        int left=0,right=k+1;
        while(right<=n){
            windowSize += (gaps[right]-gaps[left]);
            maxGap = max(maxGap,windowSize);
            left++; right++;
        }

        return maxGap;
    }
};