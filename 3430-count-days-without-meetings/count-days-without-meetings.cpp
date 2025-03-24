class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        int count=0;
        int j=0,i=0;
        while(j<days && i<n){
            if(j<meetings[i][0]){
                count+=(meetings[i][0]-j-1);
                j=meetings[i][1];
                i++;
                continue;
            }
            else{
                if(j<=meetings[i][1]){
                    j=meetings[i][1];
                    i++;
                }else{
                    i++;
                }
            }

        }

        if(j<days){
            count+=(days-j);
        }

        return count;
    }
};