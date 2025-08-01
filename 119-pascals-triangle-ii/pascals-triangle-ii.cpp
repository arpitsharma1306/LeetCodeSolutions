class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>pascal;
        pascal.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            vector<int>row(i+1);
            row[0]=1,row[i]=1;
            for(int j=1;j<i;j++){
                row[j]=pascal[j-1]+pascal[j];
            }
            pascal=row;
        }

        return pascal;

    }
};