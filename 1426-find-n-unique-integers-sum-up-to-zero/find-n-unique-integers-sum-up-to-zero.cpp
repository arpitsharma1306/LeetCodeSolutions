class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans(n);
        if(n%2==0){
            int i=0;
            int num=1;
            for(;i<n;i+=2){
                ans[i]=num;
                ans[i+1]=(-1*num);
                num++;
            }
        }
        else{
            int i=1;
            ans[0]=0;
            int num=1;
            for(;i<n;i+=2){
                ans[i]=num;
                ans[i+1]=(-1*num);
                num++;
            }
        }

        return ans;
    }
};