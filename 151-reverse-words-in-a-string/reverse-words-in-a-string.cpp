class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string str;
        string word;
        for(int i=n-1;i>=0;i--){
            while(i>=0 && (s[i]!=' ' || word.empty())){
                if(s[i]!=' ') word.push_back(s[i]);
                i--;
            }
            if(!word.empty()){
                reverse(word.begin(),word.end());
                str+=word;
                str.push_back(' ');
                word.clear();
            }
        }

        if(!word.empty()){
            reverse(word.begin(),word.end());
            str+=word;
        }else{
            str.pop_back();
        }

        return str;
    }
};