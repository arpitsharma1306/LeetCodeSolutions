class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i] && idx==-1){
                idx=i;
            }else if(s1[i]!=s2[i] && idx!=-1){
                swap(s1[i],s1[idx]);
                break;
            }
        }
        return s1==s2;
    }
};