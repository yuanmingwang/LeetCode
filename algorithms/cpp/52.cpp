class Solution {
public:
    /** 
        52. N-Queens
        Backtracking
        check 46. Permutations for backtracking framework
        check 51. N-Queens for similar problem

        Intuition:
            we can go row by row, and in each position, we need to check if the column, the 45° diagonal and the 135° diagonal had a queen before.
            
        Algorithm:

        time O(n*n!)     // n is the isValid check, and n! is the # of slot we need to check
        space O(n^2)    //  Required for board and recursive stack.
    */
    int res = 0;
    
    int totalNQueens(int n) {
        //// board[row][col] = true means there is a queen here.
        vector<vector<bool>> board(n, vector<bool>(n, false));
        backtrack(board, 0);
        return res;
    }

    /*
        It basically tries all possible placement of queen for the current row & recurses for it's next row
        Path: Rows on the board that are smaller than row have successfully placed the queen
        Selection list: All columns in row row are selections to place queens
        BC(End Condition): The row exceeds the last row of the board
    */
    void backtrack(vector<vector<bool>>& board, int row) {
        int size = board.size();
        //// bc
        if(row == size)
        {
            ++res;
            return;
        }
        //// check all col in row row
        for(int col = 0; col < size; ++col)
        {
            //// check if the spot is valid
            if(!isValid(board, row, col))
                continue;

            //// make selection
            board[row][col] = true;

            //// backtracking
            backtrack(board, row + 1);

            //// revoke selection
            board[row][col] = false;
        }
    }

    //// return true if the given [row, col] can place a queen
    //// note that we only need to check spot above row because we are doing a top to btm approach
    bool isValid(vector<vector<bool>>& board, int row, int col) {
        int size = board.size();
        //// check col above row
        for(int i = 0; i < row; ++i)
        {
            if(board[i][col] == true)
                return false;
        }
        //// check top right
        for(int i = row - 1, j = col + 1; 0 <= i and j < size; --i, ++j)
        {
            if(board[i][j] == true)
                return false;
        }
        //// check top left
        for(int i = row - 1, j = col - 1; 0 <= i and 0 <= j; --i, --j)
        {
            if(board[i][j] == true)
                return false;
        }
        return true;
    }
};