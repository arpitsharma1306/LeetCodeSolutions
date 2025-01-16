class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n,INT_MIN);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()) nge[i]=st.top();
            st.push(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nge[i]==INT_MIN){
                for(int j=0;j<i;j++){
                    if(nums[i]<nums[j]){
                        nge[i]=nums[j];
                        break;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            if(nge[i]==INT_MIN) nge[i]=-1;
        }
        

        return nge;
    }
};