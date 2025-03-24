class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto& num:nums){
            if(num<1) continue;
            pq.push(num);
        }
        int j=1;
        while(!pq.empty()){
            if(pq.top()==j){
                j++;
                pq.pop();
            }else if(j>pq.top()){
                pq.pop();
            }else{
                return j;
            }
        }

        return j;
    }
};