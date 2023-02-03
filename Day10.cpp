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

    bool isSafe(int node, vector<int>& color, bool graph[101][101], int n, int col){
        for(int j=0; j<n; j++){
            if(j!=node && graph[node][j] && color[j] == col) return false;
        }
        return true;
    }
    
    bool solve(int node, vector<int>& color, bool graph[101][101], int m, int n){
        
        if(node==n) return true;
        
        for(int i=1; i<=m; i++){
            if(isSafe(node, color, graph, n, i)){
                color[node] = i;
                if(solve(node+1, color, graph, m, n)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,0);
        color[0] = 1;
        return solve(0, color, graph, m, n);
    }

//5 Rat in a maze

    int dr[4] = {1,0,0,-1};
    int dc[4] = {0,-1,1,0};
    
    void solve(int r, int c, vector<vector<int>> &m, int n, vector<vector<int>>& vis, vector<string>& ans, string& s){
        if(r==n-1 && c==n-1){
            ans.push_back(s);
            return;
        }
        
        for(int i=0; i<4; i++){
            int nr = r+dr[i], nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<n && m[nr][nc] && !vis[nr][nc]){
                switch(i){
                    case 0: s += 'D'; break;
                    case 1: s += 'L'; break;
                    case 2: s += 'R'; break;
                    case 3: s += 'U'; break;
                }
                vis[r][c] = 1;
                solve(nr, nc, m, n, vis, ans, s);
                s.pop_back();
                vis[r][c] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(!m[0][0] || !m[n-1][n-1]) return ans;
        
        vector<vector<int>> vis(n, vector<int>(n,0));
        string s;
        solve(0, 0, m, n, vis, ans, s);
        return ans;
    }

//6 Word break

    bool solve(int i, string s, map<string,int>& mp, vector<int>& dp){
        if(i==s.size()) return true;
        if(dp[i] != -1) return dp[i];
        string temp;
        for(int j=i; j<s.size(); j++){
            temp += s[j];
            if(mp[temp]){
                if(solve(j+1, s, mp, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> mp;
        vector<int> dp(s.size(), -1);
        for(int i=0; i<wordDict.size(); i++){
            mp[wordDict[i]]++;
        }

        return solve(0, s, mp, dp);
    }
