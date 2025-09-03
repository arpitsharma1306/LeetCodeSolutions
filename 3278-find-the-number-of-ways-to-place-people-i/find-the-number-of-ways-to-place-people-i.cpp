class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    bool check(vector<int>p1,vector<int>p2,vector<vector<int>>& points){
        
        for(auto &point:points){
            if(point==p1 || point==p2) continue;
            if(p1[0]<=point[0] && point[0]<=p2[0] && p2[1]<=point[1] && point[1]<=p1[1]){
                return false;
            } 
        }

        return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),cmp);
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(points[i][1]<=points[j][1] && check(points[j],points[i],points)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};