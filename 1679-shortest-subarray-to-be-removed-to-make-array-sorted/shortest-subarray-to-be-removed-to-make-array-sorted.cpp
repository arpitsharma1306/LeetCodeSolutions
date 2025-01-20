class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(r>0 && arr[r]>=arr[r-1]){
            r--;
        }
        int result=r;

        while(l<r){
            while(r<n && arr[l]>arr[r]){
                r++;
            }

            result=min(result,r-l-1);
            l++;
            if(arr[l]<arr[l-1]) break;
        }

        return result;

    }
};