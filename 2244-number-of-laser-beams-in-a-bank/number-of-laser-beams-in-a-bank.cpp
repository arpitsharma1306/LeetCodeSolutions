class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int>lasers;

        for(string &str:bank){
            int count=0;
            for(int i=0;i<str.size();i++){
                if(str[i]=='1') count++;
            }
            if(count>0) lasers.push_back(count);
        }

        if(lasers.size()==1 || lasers.size()==0) return 0;

        int sum=0;
        for(int i=1;i<lasers.size();i++){
            sum+=(lasers[i]*lasers[i-1]);
        }

        return sum;
    }
};