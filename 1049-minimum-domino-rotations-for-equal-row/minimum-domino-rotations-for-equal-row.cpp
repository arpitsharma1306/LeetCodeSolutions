class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        vector<int>freq(7,0);
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                freq[tops[i]]++;
            }else{
                freq[tops[i]]++;
                freq[bottoms[i]]++;
            }
        }
        int idx=-1;
        for(int i=1;i<=6;i++){
            if(freq[i]==n) idx=i;
        }
        if(idx==-1) return -1;
        int tops_move=0, bottoms_move=0;
        for(int i=0;i<n;i++){
            if(tops[i]!=idx) tops_move++;
            if(bottoms[i]!=idx) bottoms_move++;
        }

        return (tops_move>bottoms_move)?bottoms_move:tops_move;
    }
};