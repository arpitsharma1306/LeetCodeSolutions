class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>parking(102,0);
        for(auto num:nums){
            parking[num[0]]++;
            parking[num[1]+1]--;
        }
        for(int i=1;i<101;i++){
            parking[i]=parking[i]+parking[i-1];
        }
        int count=0;

        for(int i=1;i<=100;i++){
            if(parking[i]>0) count++;
        }

        return count;
    }
};