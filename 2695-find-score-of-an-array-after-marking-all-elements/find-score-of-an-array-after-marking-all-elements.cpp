class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        long long score=0;

        while(!pq.empty()){
            int num=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            if(nums[idx]!=-1){
                score+=nums[idx];
                if(idx>0) nums[idx-1]=-1;
                if(idx+1<nums.size()) nums[idx+1]=-1;
            }
        }

        return score;
    }
};

// T.C. -> N(logN)