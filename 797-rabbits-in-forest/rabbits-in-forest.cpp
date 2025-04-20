class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        unordered_map<int,int>mp;
        for(int& num:answers){
            mp[num]++;
        }
        int ans=0;
        for(auto& it:mp){
            int num=it.first, freq=it.second;
            if(num==0){
                ans+=freq;
                continue;
            }
            if(freq>num+1){
                int a = static_cast<int>(std::ceil(static_cast<double>(freq) / (num+1)));
                int b = (num+1)*a;
                ans+=b;
            }else{
                ans+=(num+1);
            }

        }

        return ans;
    }
};