class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(int &x:nums){
            if(x>=0 && st.find(x)==st.end()){
                st.insert(x);
            }
        }

        if(st.empty()){
            int maxi=INT_MIN;
            for(int &x:nums){
                maxi = max(maxi,x);
            }
            return maxi;
        }

        int sum = 0;
        for(int x:st){
            sum+=x;
        }

        return sum;
    }
};