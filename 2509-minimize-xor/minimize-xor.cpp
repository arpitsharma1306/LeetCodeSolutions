class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);

        int result=0;

        //right->left canceling 1's element(1^1=0)
        for(int i=31;i>=0 and count;i--){
            if(num1 & (1<<i)){
                count--;
                result += (1<<i);
            }
        }

        //left->right, putting remaining bits from least significant to more
        for(int i=0;i<32 and count;i++){
            if((num1 & (1<<i))==0){
                count--;
                result += (1<<i);
            }
        }

        return result;
    }
};