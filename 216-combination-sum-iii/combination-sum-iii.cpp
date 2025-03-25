class Solution {
public:
    vector<vector<int>>answer;
    void solve(int k, int n,vector<int>output,int sum,int num){
        if(k==0 && sum==n){
            answer.push_back(output);
            return;
        }
        if(k<0 || sum>n || num>=10){
            return;
        }

        for(int i=num;i<10;i++){
            if(sum+i>n) break;
            output.push_back(i);
            solve(k-1,n,output,sum+i,i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>output;
        solve(k,n,output,0,1);
        return answer;
    }
};