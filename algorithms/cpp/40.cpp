class Solution {
public:
    /** 
        backtracking
        time O(2^N)
        space O(N)
    */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;
        //// we sort the candidates first. in the backtrack we prune the leaf if candidates[i] == candidates[i - 1]
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, track, res);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int start, int trackSum, vector<int>& track, vector<vector<int>>& res)
    {
        /// preorder node, add current track to res if curTrackSum == target
        if(trackSum == target)
        {
            res.push_back(track);
            return; // we can prune the leaf here because candidates is in ascending order
        }
        //// base case, cur trackSum exceed target. we can prune the leaf here because candidates is in ascending order
        if(trackSum > target)
            return;
            
        //// backtrack
        for(int i = start; i < candidates.size(); ++i)
        {
            //// prune the leaf if candidates[i] == candidates[i - 1]
            if(i > start and candidates[i] == candidates[i - 1])
                continue;
            //// preorder edge, make selection
            track.push_back(candidates[i]);
            trackSum += candidates[i];
            //// traverse
            backtrack(candidates, target, i + 1, trackSum, track, res);
            //// postorder edge, revoke selection
            track.pop_back();
            trackSum -= candidates[i];
        }
    }
};