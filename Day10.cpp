//1 Print all permutations of an array/string

    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(nums);
        }

        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            solve(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }

//2 N queens problem

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(!leftRow[row] && !lowerDiagonal[row+col] && !upperDiagonal[n-1 +col -row]){
                board[row][col] = 'Q';
                leftRow[row]=1, lowerDiagonal[row+col]=1, upperDiagonal[n-1 +col -row]=1;

                solve(col+1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);

                board[row][col] = '.';
                leftRow[row]=0, lowerDiagonal[row+col]=0, upperDiagonal[n-1 +col -row]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        vector<int> leftRow(n,0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);

        for(int i=0; i<n; i++) board[i] = s;
        solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }

//3 Sudoku solver

    bool isValid(int r, int c, char a, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[r][i] == a) return false;
            if(board[i][c] == a) return false;
            if(board[3*(r/3) + i/3][3*(c/3)+i%3] == a) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char a='1'; a<='9'; a++){
                        if(isValid(i, j, a, board)){
                            board[i][j] = a;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

//4 M coloring problem

