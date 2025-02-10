class Solution {
public:
    bool digit(char ch){
        if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9'){
            return true;
        }else{
            return false;
        }
    }
    string clearDigits(string s) {
        int n=s.size();
        string ans="";
        for(char ch:s){
            if(digit(ch)){
                ans.pop_back();
            }
            else{
                ans.push_back(ch);
            }
        }

        return ans;
    }
};