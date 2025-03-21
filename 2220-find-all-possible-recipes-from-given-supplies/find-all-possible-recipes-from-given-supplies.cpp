class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        unordered_set<string>st;
        st.insert(supplies.begin(),supplies.end());
        unordered_map<string,vector<int>>adj;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(string& ing:ingredients[i]){
                if(!st.count(ing)){
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<string>result;
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            string recipe = recipes[idx];
            result.push_back(recipe);

            for(auto &i:adj[recipe]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }

        return result;
        
    }
};