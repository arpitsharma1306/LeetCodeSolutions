class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>prefix(1001,0);

        for(auto& trip:trips){
            int passenger = trip[0];
            int pick = trip[1];
            int drop = trip[2];
            prefix[pick]+=passenger;
            prefix[drop]-=passenger;
        }
        if(prefix[0]>capacity) return false;

        for(int i=1;i<=1000;i++){
            prefix[i] = prefix[i]+prefix[i-1];
            if(prefix[i]>capacity) return false;
        }

        return true;
    }
};