class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>freq(101,0);
        for(int &num:nums){
            if(num<k){
                return -1;
            }
            freq[num]++;
        }
        int oper=0;
        for(int i=100;i>=1 && i>k;i--){
            if(freq[i]>0) oper++;
        }

        return oper;
    }
};