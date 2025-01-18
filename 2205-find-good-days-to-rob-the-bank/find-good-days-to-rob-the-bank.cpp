class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int>result;
        int count=0;
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(int i=1;i<n;i++){
            if(security[i]-security[i-1]<=0){
                count++;
            }else{
                count=0;
            }
            if(count>=time) st1.insert(i);
        }
        count=0;
        for(int i=n-2;i>=0;i--){
            if(security[i]-security[i+1]<=0){
                count++;
            }else{
                count=0;
            }
            if(count>=time) st2.insert(i);
        }
        for (const auto& element : st1) {
        // Check if the element is present in the second set
            if (st2.find(element) != st2.end()) {
            result.push_back(element);
            }
        }
        if(time==0 && n>0){
            result.push_back(0);
            if(n-1>0) result.push_back(n-1);
        }
        return result;
    
    }
};