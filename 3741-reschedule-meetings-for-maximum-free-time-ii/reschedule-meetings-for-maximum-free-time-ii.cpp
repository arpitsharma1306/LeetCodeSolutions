class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>blocks(n);
        vector<int>gaps(n+1);
        vector<int>leftgaps(n,0);
        vector<int>rightgaps(n,0);

        gaps[0]=startTime[0];
        gaps[n]=eventTime-endTime[n-1];

        for(int i=0;i<n;i++){
            blocks[i]=endTime[i]-startTime[i];
        }
        for(int i=1;i<n;i++){
            gaps[i]=startTime[i]-endTime[i-1];
        }
        for(int i=1;i<n;i++){
            leftgaps[i]=max(leftgaps[i-1],gaps[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rightgaps[i]=max(rightgaps[i+1],gaps[i+2]);
        }

        int maxFree = 0;
        for(int i=0;i<n;i++){
            if(leftgaps[i]>=blocks[i] || rightgaps[i]>=blocks[i]){
                int spaceBtw = gaps[i]+gaps[i+1]+blocks[i];
                maxFree=max(maxFree,spaceBtw);
            }else{
                int spaceBtw = gaps[i]+gaps[i+1];
                maxFree=max(maxFree,spaceBtw);
            }
        }   

        return maxFree;
    }
};