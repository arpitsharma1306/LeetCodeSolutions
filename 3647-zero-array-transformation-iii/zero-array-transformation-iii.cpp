class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(), q_sz=queries.size();
        sort(queries.begin(),queries.end());
        vector<int>diff(n+1,0);
        int sum=0, j=0;
        int cnt=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            while(j<q_sz && queries[j][0]<=i){
                pq.push(queries[j][1]);
                j++;
            }

            while(sum+diff[i]<nums[i]){
                if(pq.empty()) return -1;

                int a=pq.top();
                pq.pop(); 
                if(a>=i){
                    diff[i]++;
                    diff[a+1]--;
                    cnt++;
                }
            }
            sum+=diff[i];
        }

        return q_sz-cnt;
    }
};