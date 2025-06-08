class Solution {
public:
    void dfs(vector<int>&ans, int num,int n){
        string s = to_string(num);
        for(int i=0;i<10;i++){
            string s1 = s + to_string(i);
            int num1 = stoi(s1);
            if(num1<=n){
                ans.push_back(num1);
                dfs(ans,num1,n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<10;i++){
            if(i<=n){
                ans.push_back(i);
                dfs(ans,i,n);
            }
        }

        return ans;
    }
};