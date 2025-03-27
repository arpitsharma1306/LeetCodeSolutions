class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) > to_string(b);  
        });
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        string answer="";
        for(auto &num:nums){
            answer+=to_string(num);
        }

        if(answer[0]=='0') return "0";
        return answer;
    }
};