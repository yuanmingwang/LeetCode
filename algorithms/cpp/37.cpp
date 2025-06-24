class Solution {
public:
    /** 37. Sudoku Solver
        Backtracking

        Intuition:
            The core idea of the algorithm is very, very simple: exhaustive search. 
            For each empty cell, exhaustively try numbers from 1 to 9. 
                If an illegal number is encountered (one that already exists in the same row, column, or 3×3 area), skip it. 
                If a valid number is found, continue to exhaust the next empty cell.
            
        Algorithm:

        time O(9^(n))
            where n is number of empty cells. In the worst case, with each empty cell, we have maximum 9 options. 
            But since the board only have 1 valid solution, so this time complexity is reduced a lot.
        space O(n)
    */
    char separator = '.';
    int n = 9;  // number of row / col
    bool found = false; // mark if we find a valid solution

    void solveSudoku(vector<vector<char>>& board) {
        //// backtrack
        backtrack(board, 0);
    }
    
    /*
        Path: The positions in the board that are less than index are filled with numbers. index range [0, 9*9]
        Selection list: Numbers 1 to 9
        Termination condition: The entire board is filled with numbers
    */
    void backtrack(vector<vector<char>>& board, int index) {
        int row = index / n;
        int col = index % n;
        
        //// already found a solution
        if(found)
            return;
        //// bc. reach the end, so we have already filled all cell, which means we found a solution
        if(index == n * n)
        {
            found = true;
            return;
        }
        //// if the cell already have a number, we dont need to check this cell
        if(board[row][col] != separator)
        {
            backtrack(board, index + 1);
            return;
        }

        //// backtrack, check this cell
        for(char ch = '1'; ch <= '9'; ++ch)
        {
            //// Pruning, skip invalid number
            if(!isValid(board, row, col, ch))
                continue;

            //// make selection
            board[row][col] = ch;

            //// backtrack
            backtrack(board, index + 1);

            //// return if we find a solution
            // do not revoke the selection. because otherwise board[i][j] will be reset to '.'
            if(found)
                return;
            
            //// revoke selection
            board[row][col] = '.';
        }
    }

    //// return true if we can place the char in the (row, col) position
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < n; ++i)
        {
            //// check row
            if(board[row][i] == ch) return false;
            //// check col
            if(board[i][col] == ch) return false;
            //// check block
            int block_row = (row / 3) * 3 + (i / 3);
            int block_col = (col / 3) * 3 + (i % 3);
            if(board[block_row][block_col] == ch) return false;
        }
        return true;
    }
};