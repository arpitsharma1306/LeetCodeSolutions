class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<int>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
            st.clear();
        }

        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
            st.clear();
        }

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
        }
        st.clear();

        for(int i=0;i<3;i++){
            for(int j=3;j<6;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
        }
        st.clear();

        for(int i=0;i<3;i++){
            for(int j=6;j<9;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
        }
        st.clear();

        for(int i=3;i<6;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
        }
        st.clear();

        for(int i=3;i<6;i++){
            for(int j=3;j<6;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
        }
        st.clear();

        for(int i=3;i<6;i++){
            for(int j=6;j<9;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
        }
        st.clear();

        for(int i=6;i<9;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
        }
        st.clear();

        for(int i=6;i<9;i++){
            for(int j=3;j<6;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
        }
        st.clear();

        for(int i=6;i<9;i++){
            for(int j=6;j<9;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'a';
                if(st.count(num)) return false;
                st.insert(num);
            }
        }
        st.clear();

        return true;
        
    }
};