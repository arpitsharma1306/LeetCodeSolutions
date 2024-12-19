class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int chunks=1;
        vector<int>max_arr(n);
        vector<int>min_arr(n);
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[n-i-1]);
            max_arr[i]=maxi;
            min_arr[n-i-1]=mini;
        }

        for(int i=0;i<n-1;i++){
            if(max_arr[i]<=min_arr[i+1]) chunks++;
        }

        return chunks;
    }
};