class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>left(n,INT_MAX);
        vector<int>right(n,INT_MAX);
        int time=INT_MAX;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                time=1;
            }else if(dominoes[i]=='L'){
                time=INT_MAX;
            }else if(dominoes[i]=='.'){
                if(time!=INT_MAX){
                    right[i]=time;
                    time++;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                time=1;
            }else if(dominoes[i]=='R'){
                time=INT_MAX;
            }else if(dominoes[i]=='.'){
                if(time!=INT_MAX){
                    left[i]=time;
                    time++;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(dominoes[i]=='L' || dominoes[i]=='R') continue;

            if(left[i]==right[i]) continue;
            dominoes[i]=(left[i]<right[i])?'L':'R';
        }

        return dominoes;
    }
};