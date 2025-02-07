class Solution {
public:
    typedef pair<long long,int> P;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        unordered_map<int,long long>mp;
        priority_queue<P,vector<P>>pq;
        vector<long long>ans(n);
        for(int i=0;i<n;i++){
            mp[nums[i]]+=freq[i];
            pq.push({mp[nums[i]],nums[i]});
            while(pq.size() && mp[pq.top().second]!=pq.top().first) pq.pop();
            ans[i]=pq.top().first;
        }

        return ans;
    
    }
};