class Solution {
public:
    /** 36. Valid Sudoku   
        Hash Table

        Intuition:
            For each row, we create a HashSet to check for duplicates in each row.
            For each column, we also create a HashSet to check for duplicates in each column.
            For each block, we also create a HashSet to check for duplicates in each square, but we need to convert the position (r, c) in the board to square by:
                Square row: sr = r / 3.
                Square col: sc = c / 3.
                Square 3x3 block: sBlock = sr * 3 + sc.

        Algorithm:

        time O(n^2) where n = 9
        space O(n^2)
    */

    char separator = '.';
    int n = 9;  // number of row / col
    int b = 3;  // size of the block

    bool isValidSudoku(vector<vector<char>>& board) {
        //// init unordered_set for each row/col/block. there are n row/col/block in total
        unordered_set<char> uset_row[n];
        unordered_set<char> uset_col[n];
        unordered_set<char> uset_block[n];

        //// check value
        for(int row = 0; row < n; ++row)
        {
            for(int col = 0; col < n; ++col)
            {
                char val = board[row][col];
                //// find a seperator, skip
                if(val == separator)
                    continue;
                //// check if the val is already in same row / col / block
                int block = (row / b) * b + (col / b);
                if(uset_row[row].count(val) or uset_col[col].count(val) or uset_block[block].count(val))
                    return false;
                //// insert val into the corresponding unordered_set
                uset_row[row].insert(val);
                uset_col[col].insert(val);
                uset_block[block].insert(val);
            }
        }
        return true;
    }
};

/** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
class Solution {
public:
    /** 36. Valid Sudoku
        Bitmask

        Intuition:
            Since we only need to store 2 states (exist, not exist) and store up to 9 positions.
            So to save space, we can store in the bitmask, i th bit represent the existence of the number
            
            For each block, we need to convert the position (r, c) in the board to square by:
                Square row: sr = r / 3.
                Square col: sc = c / 3.
                Square 3x3 block: sBlock = sr * 3 + sc.

        Algorithm:

        time O(n^2) where n = 9
        space O(n)
    */

    char separator = '.';
    int n = 9;  // number of row / col
    int b = 3;  // size of the block

    bool isValidSudoku(vector<vector<char>>& board) {
        //// init Bitmask for each row/col/block. there are n row/col/block in total
        vector<int> v_row(n);
        vector<int> v_col(n);
        vector<int> v_block(n);

        //// check value
        for(int row = 0; row < n; ++row)
        {
            for(int col = 0; col < n; ++col)
            {
                //// find a seperator, skip
                if(board[row][col] == separator)
                    continue;
                //// check if the val is already in same row / col / block
                int val = board[row][col] - '0';
                int block = (row / b) * b + (col / b);
                if(checkBitmask(v_row[row], val) or checkBitmask(v_col[col], val) or checkBitmask(v_block[block], val))
                    return false;
                //// insert val into the corresponding bitmask
                // example: val = 5
                //  1 << 5: Create a mask 100000 (binary)
                //  |= operation: Retain existing bitmask and add new bitmask (bitwise OR operation)
                v_row[row] |= 1 << val;
                v_col[col] |= 1 << val;
                v_block[block] |= 1 << val;
            }
        }
        return true;
    }

    /*  Function: Check if the k-th bit of the integer x is 1
        Operation process:
            x >> k: Right shift x's binary representation by k bits, moving the target bit to the least significant bit
            & 1: Use bitwise AND operation to extract the least significant bit
        Return value:
            1 → The k-th bit is set (the number has appeared)
            0 → The k-th bit is not set (the number has not appeared)
    */
    int checkBitmask(int x, int k) {
        return (x >> k) & 1;
    }
};