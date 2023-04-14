class Solution {
public:
    /** 
        DFS / backtracking

        time O(M * N * (4 ^ L)), where M, N = length & height of the matrix. L = word.size()
        space O(M * N)
    */
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        //// for each location, try to find a match
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(dfs(board, word, i, j, 0, visited))
                    return true;
            }
        }
        return false;
    }

    //// start from board[i][j], trying to match word[p]
    // time complex: O(4^L)
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int p, vector<vector<bool>>& visited)
    {
        //// reach the end, finishing searching all chars, return true
        if(p == word.size())
            return true;
        //// out of bound
        if(i < 0 or i >= board.size())
            return false;
        if(j < 0 or j >= board[0].size())
            return false;
        //// word[p] does not match
        if(board[i][j] != word[p])
            return false;
        //// visited
        if(visited[i][j])
            return false;
        
        //// dfs / backtrack, set visited and search 4 directions
        visited[i][j] = true;
        bool up = dfs(board, word, i - 1, j, p + 1, visited);       // up
        bool down = dfs(board, word, i + 1, j, p + 1, visited);     // down
        bool left = dfs(board, word, i, j - 1, p + 1, visited);     // left
        bool right = dfs(board, word, i, j + 1, p + 1, visited);    // right
        visited[i][j] = false;

        return up or down or left or right;
    }
};