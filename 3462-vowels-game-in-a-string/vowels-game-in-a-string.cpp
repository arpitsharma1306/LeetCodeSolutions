class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.size();
        string vowels = "aeiou";
        int count = 0;
        for(char& ch:s){
            if(vowels.find(ch)!=string::npos) count++;
        }
        if(count==0) return false;

        return true;
    }
};