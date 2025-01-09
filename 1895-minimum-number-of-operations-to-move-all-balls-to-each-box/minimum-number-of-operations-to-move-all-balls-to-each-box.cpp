class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>answer(n,0);

        int cumValue=0,cumValueSum=0;
        //  from left -> right cummalative value nikal rhe aur sath mai us cummalative value ko sum bhi kar rhe
        for(int i=0;i<n;i++){
            answer[i] = cumValueSum;
            cumValue += boxes[i]=='0' ? 0:1;
            cumValueSum+=cumValue;
        }

        cumValue=0,cumValueSum=0;
        // yahi same right -> left karna h aur answer mai add karte jana h
        for(int i=n-1;i>=0;i--){
            answer[i] += cumValueSum;
            cumValue += boxes[i]=='0' ? 0:1;
            cumValueSum+=cumValue;
        }

        return answer;

    }
};