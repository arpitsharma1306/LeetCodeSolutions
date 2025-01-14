class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;

        int i=0; //s string
        int j=0; //spaces vector

        while(i<s.size()){
            if(j<spaces.size() && i==spaces[j]){
                ans+=' ';
                j++;
            }else{
                ans+=s[i];
                i++;
            }
        }

        return ans;
    }
};