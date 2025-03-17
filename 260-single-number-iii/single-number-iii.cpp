class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==2) return {nums[0],nums[1]};
        int sum=0;
        for(int& num:nums){
            sum^=num;
        }
        int bitset=0;
        for(int i=0;i<31;i++){
            if(sum & (1<<i)){
                bitset=i;
                break;
            }
        }

        vector<int>grp1, grp2;

        for(int& num:nums){
            if(num & (1<<bitset)){
                grp1.push_back(num);
            }else{
                grp2.push_back(num);
            }
        }

        int ans1=0,ans2=0;

        for(int& num:grp1){
            ans1^=num;
        }
        for(int& num:grp2){
            ans2^=num;
        }

        return {ans1,ans2};
    }
};