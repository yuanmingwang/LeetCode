class Solution {
public:
    /** 
        backtracking
        time O(N * N!)  // N for the is valid check, and N! for the # of slot need to check
        space O(N)
    */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        backtracking(board, res, 0);
        return res;
    }
private:
    //// top to btm
    //// row: the row we are checking
    void backtracking(vector<string>& board, vector<vector<string>>& res, int row)
    {
        if(row == board.size())
        {
            res.push_back(board);
            return;
        }
        //// check all col in row row
        for(int col = 0; col < board[row].size(); ++col)
        {
            //// check if the spot is valid
            if(!isValid(board, row, col))
                continue;
            
            //// make selection
            board[row][col] = 'Q';

            //// traverse
            backtracking(board, res, row + 1);

            //// revoke selection
            board[row][col] = '.';
        }
    }

    //// return true if the given [row, col] can place a queen
    //// note that we only need to check spot above row because we are doing a top to btm approach
    bool isValid(vector<string>& board, int row, int col)
    {
        int size = board.size();    // n * n board, row size = col size
        //// check col
        for(int i = 0; i < row; ++i)
        {
            if(board[i][col] == 'Q')
                return false;
        }
        //// check top left
        for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; --i, --j)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        //// check top right
        for(int i = row - 1, j = col + 1; i >= 0 and j < size; --i, ++j)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
};