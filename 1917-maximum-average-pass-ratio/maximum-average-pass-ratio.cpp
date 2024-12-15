class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,int>>pq;

        for(int i=0;i<n;i++){
            double x=classes[i][0],y=classes[i][1];
            double value=(x+1)/(y+1)-x/y;
            pq.push({value,i});
        }

        while(extraStudents--){
            int idx=pq.top().second;
            pq.pop();

            classes[idx][0]+=1;
            classes[idx][1]+=1;
            double x=classes[idx][0],y=classes[idx][1];
            double value=(x+1)/(y+1)-x/y;
            pq.push({value,idx});
        }

        double ans=0;

        for(int i=0;i<n;i++){
            double x=classes[i][0],y=classes[i][1];
            ans+=(x/y);
        }
        ans/=n;

        return ans;


    }
};