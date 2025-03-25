class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(begin(rectangles),end(rectangles));
        int lines=0;
        int i=0, j=0;
        while(i<rectangles.size() && j<n){
            if(rectangles[i][0]<j && rectangles[i][2]>j){
                j=rectangles[i][2];
                i++;
            }else if(rectangles[i][0]>=j){
                lines++;
                j=rectangles[i][2];
                i++;
            }else if(rectangles[i][2]<=j){
                i++;
            }else{
                i++;
                j=rectangles[i][2];
            }
        }
        if(lines>=3) return true;
        cout<<lines<<" ";
        i=0, j=0, lines=0;
        sort(begin(rectangles),end(rectangles),[](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });

        while(i<rectangles.size() && j<n){
            if(rectangles[i][1]<j && rectangles[i][3]>j){
                j=rectangles[i][3];
                i++;
            }else if(rectangles[i][1]>=j){
                lines++;
                j=rectangles[i][3];
                i++;
            }else if(rectangles[i][3]<=j){
                i++;
            }else{
                i++;
                j=rectangles[i][3];
            }
        }
        if(lines>=3) return true;
        cout<<lines<<" ";
        return false;
    }
};