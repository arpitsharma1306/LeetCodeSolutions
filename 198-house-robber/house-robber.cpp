class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];

        vector<int>t(n+1,0); // n+1 because house no. ki starting 1 se h
        t[1]=nums[0]; //pehla ghar h to max. pehla hi rob karenge
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+t[i-2]; //wo wala house and usse do pehle ghar
            int skip=t[i-1];            // last wala ghar

            t[i]=max(steal,skip);
        }

        return t[n];
    }
};