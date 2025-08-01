class Solution {
public:
    long long ncr(int n,int r){
        if(r>n-r){
            r=n-r;
        }
        long long res = 1;
        for(int i=0;i<r;i++){
            res = res * (n-i)/(i+1);
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1);
        ans[0]=ans[rowIndex]=1;
        for(int i=1;i<rowIndex;i++){
            ans[i] = (int)ncr(rowIndex,i);
        }
        return ans;

    }
};