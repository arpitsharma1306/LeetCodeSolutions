class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int count=0;
        while(pq.size()>=2&&pq.top()<k){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            if(a*2+b<=1000000000)
               pq.push(a*2+b);
            else{
                pq.push(1000000000);
            }
            count++;
        }
        return count;
    }
};