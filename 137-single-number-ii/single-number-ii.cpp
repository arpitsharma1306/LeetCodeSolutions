class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>count(32,0);
        for(int num:nums){
            for(int i=0;i<32;i++){
                bool i_bit = num & 1<<i;
                if(i_bit==1) count[i]++;
            }
        }

        int ans=0;
        for(int i=0;i<32;i++){
            if(count[i]%3!=0){
                ans+= 1<<i;
            }
        }

        return ans;
    }
};