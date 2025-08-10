class Solution {
public:
    string sorted(int num){
        string s = to_string(num);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string ans = sorted(n);
        for(int i=0;i<=31;i++){
            if(sorted((1<<i))==ans) return true;
        }
        return false;
    }
};