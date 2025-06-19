class NumMatrix {
public:
    /** 
        Array, Prefix Sum

        Intuition: 
            We can maintain a two-dimensional preSum array that records the sum of the elements of the matrix with the origin as the vertice, 
            and then we can calculate the sum of the elements of any submatrix with a few addition and subtraction operations:

            preSum (i, j) stores the sum of the area from (0, 0) to (i, j)
                if matrix = (3, 3), preSum = 
                    0 0 0 0
                    0 1 2 3
                    0 4 5 6
                    0 7 8 9
            
            preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + matrix[i-1][j-1]

            So, we use the same idea to find the specific area's sum.
            areaSum = preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];

        time O(m * n) where m is the number of rows, n is the number of columns in the matrix
        space O(m * n)
    **/
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(); 
        int col = row <= 0 ? 0 : matrix[0].size();
        if(row == 0 or col == 0)
            return;
        preSum = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
        for(int i = 1; i <= row; ++i)    // <= because i, j start with 1, [i][j] stores matrix[i - 1][j - 1]
        {
            for(int j = 1; j <= col; ++j)
            {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */