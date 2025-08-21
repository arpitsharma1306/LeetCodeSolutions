class Solution {
public:
    int oneArrayCount(vector<int>& v){
        int subCount = 0;
        int cons = 0; //consecutive ones count
        for(int i=0;i<v.size();i++){
            if(v[i]==0) cons = 0;
            else cons++;

            subCount += cons;
        }

        return subCount;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int res = 0;

        for(int start = 0;start<m;start++){
            vector<int>v(n,1);
            for(int end = start;end<m;end++){
                
                for(int col = 0;col<n;col++){
                    v[col] = v[col] & mat[end][col];
                }

                res += oneArrayCount(v);
            }
        }

        return res;
    }
};