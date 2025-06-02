class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        char a1=s1[0],a2=s1[1],a3=s1[2],a4=s1[3];
        char b1=s2[0],b2=s2[1],b3=s2[2],b4=s2[3];

        bool first_pair=false;
        if((a1==b1 && a3==b3) || (a1==b3 && a3==b1)) first_pair=true;

        bool sec_pair=false;
        if((a2==b2 && a4==b4) || (a2==b4 && a4==b2)) sec_pair=true;

        return first_pair & sec_pair;
    }
};