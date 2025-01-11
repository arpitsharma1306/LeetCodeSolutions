class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        long long sum=0;
        int mini=INT_MAX;
        int x=-1,y=-1;
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    count++;
                    matrix[i][j]=abs(matrix[i][j]);
                }
                if(mini>matrix[i][j]){
                    mini=matrix[i][j];
                    x=i,y=j;
                }
                sum+=matrix[i][j];
            }
        }

        if(count%2==1){
            sum-=mini;
            sum-=mini;
        }

        return sum;
    }
};