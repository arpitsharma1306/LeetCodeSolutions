class Solution {
public:
    int maxDiff(int num) {
        string number = to_string(num);
        char re_large=number[0], re_small=number[0];
        for(int i=0;i<number.size();i++){
            if(number[i]=='9') continue;
            re_large = number[i];
            break;
        }
        for(int i=0;i<number.size();i++){
            if(number[i]=='1' || number[i]=='0') continue;
            re_small = number[i];
            break;
        }
        string small,large;
        for(int i=0;i<number.size();i++){
            if(number[i]==re_large){
                large+='9';
            }else{
                large+=number[i];
            }
        }
        for(int i=0;i<number.size();i++){
            if(number[i]==re_small){
                if(re_small!=number[0]){
                    small+='0';
                }
                else small+='1';
            }else{
                small+=number[i];
            }
        }

        int smaller = stoi(small);
        int larger = stoi(large);

        return larger-smaller;
    }
};