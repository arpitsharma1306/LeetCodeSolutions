class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int>mp;
        for(int &num:nums){
            if(num<0){
                num%=value;
                num+=value;
            }
            mp[num%value]++;
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(mp[ans%value]>0){
                mp[ans%value]--;
            }else{
                return ans;
            }
            ans++;
        }

        return ans;
    }
};