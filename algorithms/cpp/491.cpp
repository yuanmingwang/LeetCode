class Solution {
public:
    /** 
        Backtracking, DFS
        Subset (Combinations) (repetition, no multiple-choice)
        Similar to 40. Combination Sum II (https://leetcode.com/problems/combination-sum-ii/description/)
        Similar to 90. Subsets II (https://leetcode.com/problems/subsets-ii/description/)
        In 40 & 90, we sort nums to avoid repetition. However, we can not sort nums here because we need to find non-decreasing subsequences
        Therefore, we need to matain a unorder_set<int> used to remove repetition
        The unordered_set is used to avoid [4,6,7(1)] and [4,6,7(2)] in a same level when we dfs. 
        But it will not skip [4,6,7(1),7(2)], because 7(2) is added in the next dfs level of [4,6,7(1)]. 
        Every time we start a "next level dfs", we will initialize a new unordered_set.

        time O(2^N)
        space O(N)
    */
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(nums, 0, track, res);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track, vector<vector<int>>& res)
    {
        //// preorder node
        //// bc
        // find a valid res
        if(track.size() >= 2)
            res.push_back(track);

        unordered_set<int> used;
        //// backtrack
        for(int i = start; i < nums.size(); ++i)
        {
            //// preorder edge
            // continue if it is not ascending
            if(!track.empty() and nums[i] < track[track.size() - 1])
                continue;
            // continue if we already used the number in the current dfs level as explained above
            if(used.find(nums[i]) != used.end())
                continue;
            // make selection
            track.push_back(nums[i]);
            used.insert(nums[i]);

            //// traverse
            backtrack(nums, i + 1, track, res);

            //// postorder edge
            // revoke selection
            track.pop_back();
        }
    }
};