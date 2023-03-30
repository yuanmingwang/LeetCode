class Solution {
public:
    /** 
        backtracking
        combination is a subproblem of subset. for subset of number in range [1, n], combination(n, k) is all elements of subset at level k
        for eaxmple, n = 3, k = 2, combination(3, 2) = [ [1,2],[1,3],[2,3] ], which is all elements at level 2

        time O(2^N)
        space O(N)
    */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(n, k, 1, track, res);
        return res;
    }

    void backtrack(int n, int k, int start, vector<int>& track, vector<vector<int>>& res)
    {
        //// preorder node, add current track to res if cur level is k
        if(track.size() == k)
        {
            res.push_back(track);
            return; // find a match in the current leaf so we can return directly
        }
            
        //// backtrack
        for(int i = start; i <= n; ++i)
        {
            //// preorder edge, make selection
            track.push_back(i);
            //// traverse
            backtrack(n, k, i + 1, track, res);
            //// postorder edge, revoke selection
            track.pop_back();
        }
    }
};