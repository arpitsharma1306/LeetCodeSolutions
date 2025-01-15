class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        vector<vector<int>>matrix(26,vector<int>(n+1,0));
        int len=0;
        int prev_char=s[0];
        for(int i=0;i<n;i++){
            char curr_char=s[i];
            if(curr_char==prev_char){
                len++;
                matrix[curr_char-'a'][len]+=1;
            }else{
                len=1;
                matrix[curr_char-'a'][len]+=1;
                prev_char=curr_char;
            }
        }

        int result=0;
        for(int i=0;i<26;i++){
            int cumSum=0;
            for(int j=n;j>0;j--){
                cumSum+=matrix[i][j];
                if(cumSum>=3){
                    result=max(result,j);
                    break;
                }
            }
        }

        return result==0?-1:result;
    }
};