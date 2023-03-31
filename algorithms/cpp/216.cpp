class Solution {
public:
    /** 
        backtracking
        Combinations (Subset) (no repetition, no multiple-choice)

        time O(2^N)
        space O(N)
    */
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(k, n, 1, 0, track, res);
        return res;
    }

    void backtrack(int k, int target, int start, int trackSum, vector<int>& track, vector<vector<int>>& res)
    {
        //// preorder node, add res
        if(track.size() == k and target == trackSum)
        {
            res.push_back(track);
            return;
        }
        //// bc. cur track.size() exceed k. we can prune the leaf
        if(track.size() > k)
            return;
        //// bc. cur trackSum exceed target. we can prune the leaf
        if(trackSum > target)
            return;

        //// backtrack
        for(int i = start; i <= 9; ++i)
        {
            //// preorder edge, make selection
            track.push_back(i);
            trackSum += i;
            //// traverse
            backtrack(k, target, i + 1, trackSum, track, res);
            //// postorder edge, revoke selection
            track.pop_back();
            trackSum -= i;
        }
    }
};