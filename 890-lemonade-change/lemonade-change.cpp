class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;

        for(int &x:bills){
            if(x==5){
                five++;
            }
            if(x==10){
                if(five<=0) return false;

                five--;
                ten++;
            }

            if(x==20){
                if(five<=0) return false;
                if(!((five>=3) || (five>=1 && ten>=1))) return false;

                if(ten>0){
                    ten--;
                    five--;
                }
                else{
                    five-=3;
                }
            }
        }

        return true;
    }
};