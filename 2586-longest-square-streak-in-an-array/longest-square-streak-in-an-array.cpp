class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int result=0;
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        unordered_set<int>st(nums.begin(),nums.end());
        
        for(int &num:nums){
            int count=0;
            int _sqrt=sqrt(num);
            int val=num;
            while(_sqrt*_sqrt==val && st.find(_sqrt)!=st.end()){
                count++;
                val=_sqrt;
                _sqrt=sqrt(_sqrt);
            }
            result=max(result,count);
        }


        return result==0?-1:result+1;

    }
};