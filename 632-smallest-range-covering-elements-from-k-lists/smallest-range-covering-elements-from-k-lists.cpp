class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<tuple<int, int, int>> pq_max;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq_min;
        for(int i=0;i<n;i++){
            pq_max.push({nums[i][0],i,0});
            pq_min.push({nums[i][0],i,0});
        }
        vector<int>range(2);
        range[0]=get<0>(pq_min.top());
        range[1]=get<0>(pq_max.top());

        while(true){
            auto [x,arr_idx,idx] = pq_min.top();
            pq_min.pop();
            if(idx==nums[arr_idx].size()-1) break;
            int number = nums[arr_idx][idx+1];
            pq_min.push({number,arr_idx,idx+1});
            pq_max.push({number,arr_idx,idx+1});
            int maxi = get<0>(pq_max.top());
            int mini = get<0>(pq_min.top());
            if(maxi-mini<range[1]-range[0]){
                range[1]=maxi;
                range[0]=mini;
            }else if(maxi-mini==range[1]-range[0] && maxi<range[1]){
                range[1]=maxi;
                range[0]=mini;
            }
        }

        return range;
    }
};