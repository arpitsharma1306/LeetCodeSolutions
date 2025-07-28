class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int largest = nums[0][0];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq_min;
        for(int i=0;i<n;i++){
            largest = max(largest,nums[i][0]);
            pq_min.push({nums[i][0],i,0});
        }
        vector<int>range(2);
        range[0]=get<0>(pq_min.top());
        range[1]=largest;

        while(true){
            auto [x,arr_idx,idx] = pq_min.top();
            pq_min.pop();
            if(idx==nums[arr_idx].size()-1) break;
            int number = nums[arr_idx][idx+1];
            pq_min.push({number,arr_idx,idx+1});
            largest = max(largest,number);
            int mini = get<0>(pq_min.top());
            if(largest-mini<range[1]-range[0]){
                range[1]=largest;
                range[0]=mini;
            }else if(largest-mini==range[1]-range[0] && largest<range[1]){
                range[1]=largest;
                range[0]=mini;
            }
        }

        return range;
    }
};