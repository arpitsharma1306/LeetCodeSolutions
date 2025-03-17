class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int xor1=0, xor2=0;

        for(int num:nums){
            xor1^=num;
            xor2^=(num+1);
        } 

        return xor1==0 && xor2==0;
    }
};