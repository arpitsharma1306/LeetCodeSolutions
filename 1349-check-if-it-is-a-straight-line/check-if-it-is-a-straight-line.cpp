class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cod) {
        int n=cod.size();
        sort(cod.begin(),cod.end());
        double slope1=double(cod[1][0]-cod[0][0])/double(cod[1][1]-cod[0][1]);
        for(int i=2;i<n;i++){
            double slope2=double(cod[i][0]-cod[i-1][0])/double(cod[i][1]-cod[i-1][1]);
            if(slope1!=slope2) return false;
        }

        return true;
    }
};