class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes=0,ones=0,twoes=0;
        for(int &num:nums){
            if(num==0) zeroes++;
            if(num==1) ones++;
            if(num==2) twoes++;
        }
        int i=0;
        while(zeroes--){
            nums[i++]=0;
        }
        while(ones--){
            nums[i++]=1;
        }
        while(twoes--){
            nums[i++]=2;
        }

    }
};