class Solution {
public:
    /** 
        dp, iteration, btm up
        
        def: 
            dp[i][j] = max length(width) of the square that can be formed with [i, j] as its bottom-right square
        stf:
            1. m[i][j] = 0
                dp[i][j] = 0 
                because 0 can not formed a matrix
            2. m[i][j] = 1
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                because inorder to form a square, top, left, top-left square must be 1
        bc:
            dp[i][0] = matrix[i][0] == '0' ? 0 : 1
            dp[0][j] = matrix[0][j] == '0' ? 0 : 1

        time O(m * n) where m, n = # of col & row of the square
        space O(n)
    */
    int maximalSquare(vector<vector<char>>& matrix) {
        //// o(n)
        int res = 0, dp_i1_j1, temp;
        int size_col = matrix.size();       // # of col
        int size_row = matrix[0].size();    // # of row
        vector<int> dp(size_row);
        // //// bc
        // for(int j = 0; j < size_row; ++j)
        //     dp[j] = matrix[0][j] == '0' ? 0 : 1;
        //// dp. we need dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] to find dp[i][j]
        for(int i = 0; i < size_col; ++i)
        {
            for(int j = 0; j < size_row; ++j)
            {
                temp = dp[j];
                //// bc
                if(i == 0 or j == 0)
                    dp[j] = matrix[i][j] == '0' ? 0 : 1;
                else
                {
                    if(matrix[i][j] == '0') // 0
                        dp[j] = 0;
                    else    // 1
                        dp[j] = min(min(dp[j], dp[j - 1]), dp_i1_j1) + 1;
                }
                dp_i1_j1 = temp;    // store dp[i - 1][j - 1]
                res = max(res, dp[j]);
                // cout<<dp[j]<<" ";
            }
            // cout<<endl;
        }
        return res * res;

        // //// o(nm)
        // int res = 0;
        // int size_col = matrix.size();       // # of col
        // int size_row = matrix[0].size();    // # of row
        // vector<vector<int>> dp(size_col, vector<int>(size_row));
        // //// bc
        // for(int i = 0; i < size_col; ++i)
        //     dp[i][0] = matrix[i][0] == '0' ? 0 : 1;
        // for(int j = 0; j < size_row; ++j)
        //     dp[0][j] = matrix[0][j] == '0' ? 0 : 1;
        // //// dp
        // for(int i = 1; i < size_col; ++i)
        // {
        //     for(int j = 1; j < size_row; ++j)
        //     {
        //         if(matrix[i][j] == '0') // 1.
        //             dp[i][j] = 0;
        //         else    // 2.
        //             dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        //     }
        // }
        // // for(auto&i : dp)
        // // {
        // //     for(auto&j : i)
        // //         cout<<j<< " ";
        // //     cout<<endl;
        // // }
        // //// find max
        // for(auto&i : dp)
        //     for(auto&j : i)
        //         res = max(res, j);

        // return res * res;
    }
};