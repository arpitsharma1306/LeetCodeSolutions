class Solution {
public:
    vector<int>getNSL(vector<int>&nums,int n){
        stack<int>st;
        vector<int>result(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()) result[i]=st.top();

            st.push(i);
        }

        return result;
    }

    vector<int>getNSR(vector<int>&nums,int n){
        stack<int>st;
        vector<int>result(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty()) result[i]=st.top();

            st.push(i);
        }

        return result;
    }

    vector<int>getNGL(vector<int>&nums,int n){
        stack<int>st;
        vector<int>result(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty()) result[i]=st.top();

            st.push(i);
        }

        return result;
    }

    vector<int>getNGR(vector<int>&nums,int n){
        stack<int>st;
        vector<int>result(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(!st.empty()) result[i]=st.top();

            st.push(i);
        }

        return result;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>NSL = getNSL(nums,n);
        vector<int>NSR = getNSR(nums,n);
        vector<int>NGL = getNGL(nums,n);
        vector<int>NGR = getNGR(nums,n);

        long long sum=0;
        for(int i=0;i<n;i++){
            int ls = i-NGL[i];
            int rs = NGR[i]-i;
            long long total_ways=ls*rs;
            sum+=(total_ways*nums[i]);
        }

        for(int i=0;i<n;i++){
            int ls = i-NSL[i];
            int rs = NSR[i]-i;
            long long total_ways=ls*rs;
            sum-=(total_ways*nums[i]);
        }


        return sum;
    }
};