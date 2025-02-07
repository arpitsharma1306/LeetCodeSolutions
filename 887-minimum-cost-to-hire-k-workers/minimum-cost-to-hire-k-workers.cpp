class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& minWage, int k) {
        int n=minWage.size();
        vector<pair<double,int>>ratio;
        for(int i=0;i<n;i++){
            ratio.push_back({(double)minWage[i]/quality[i],quality[i]});
        }
        sort(begin(ratio),end(ratio));
        priority_queue<int,vector<int>>pq;
        int sum_quality=0;
        for(int i=0;i<k;i++){
            sum_quality+=ratio[i].second;
            pq.push(ratio[i].second);
        }

        double result=ratio[k-1].first*sum_quality;
        for(int manager=k;manager<n;manager++){
            double manager_ratio=ratio[manager].first;
            sum_quality+=ratio[manager].second;
            pq.push({ratio[manager].second});
            if(pq.size()>k){
                sum_quality-=pq.top();
                pq.pop();
            }
            result=min(result,ratio[manager].first*sum_quality);
        }

        return result;
    }
};