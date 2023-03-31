class Solution {
public:
    /** 
        backtracking
        Combinations (Subset) (no repetition, multiple-choice)

        time O(2^N)
        space O(N)
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(candidates, target, 0, 0, track, res);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int start, int trackSum, vector<int>& track, vector<vector<int>>& res)
    {
        //// preorder node, add to res
        if(trackSum == target)
        {
            res.push_back(track);
            return;
        }
        //// bc. cur trackSum exceed target. we can prune the leaf here
        if(trackSum > target)
            return;

        //// backtrack
        for(int i = start; i < candidates.size(); ++i)
        {
            //// preorder edge, make selection
            track.push_back(candidates[i]);
            trackSum += candidates[i];
            //// traverse
            // we start from i instead of i + 1. this means we can select the same element multiple times. the above bc will prevent the infinity loop
            backtrack(candidates, target, i, trackSum, track, res);
            //// postorder edge, revoke selection
            track.pop_back();
            trackSum -= candidates[i];
        }
    }
};