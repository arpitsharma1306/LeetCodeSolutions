class Solution {
public:
    string largestGoodInteger(string num) {
        string maxi="";
        
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1] && num[i-1]==num[i-2]){
                if(maxi.empty()){
                    cout<<"yes";
                    maxi = string()+num[i-2]+num[i-1]+num[i];
                }
                else{
                    string new_num = string()+num[i-2]+num[i-1]+num[i];
                    if(new_num>maxi) maxi=new_num;
                }
            }
        }

        return maxi;
    }
};