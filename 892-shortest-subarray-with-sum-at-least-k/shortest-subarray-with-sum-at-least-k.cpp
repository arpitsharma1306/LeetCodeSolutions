class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long n=nums.size();
        deque<pair<long long,long long>>dq;
        long long sum=0;
        long long len=INT_MAX;
        for(long long i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=k) len=min(len,i+1);

            pair<long long,long long>curr={INT_MIN,INT_MIN};
            while(!dq.empty() && (sum-dq.front().second>=k)){
                curr=dq.front();
                dq.pop_front();
            }
            if(curr.second!=INT_MIN){
                len=min(len,i-curr.first);
            }

            while(!dq.empty() && sum<=dq.back().second){
                dq.pop_back();
            }

            dq.push_back({i,sum});

        }

        return len==INT_MAX ? -1:len;
    }
};