class Solution {
public:
    /** 47. Permutations II
        backtracking
        Permutations (repetition, no multiple-choice)

        we sort the nums first to fix the position of each element
        in the backtrack we prune the leaf if nums[i] == nums[i - 1] and if the previous same element has not been used
        for example, we have [1, 2, 2']. we want to make sure 2 is in front of 2' in all permutation, so we just prune the leaf that 2' is used before 2
        we will get the correct permutation [ [1,2,2'],[2,1,2'],[2,2',1] ] out of 
        [
            [1,2,2'],[1,2',2],
            [2,1,2'],[2,2',1],
            [2',1,2],[2',2,1]
        ]

        time O(N! * N) 
            for recursive call, we have O(branches ^ depth), here we have n, n-1, n-2...1 branches, so total recursive call is n!. N for for loop
        space O(N)
    */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> path(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, track, path, res);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& path, vector<vector<int>>& res)
    {
        //// preorder node, update res if we find a permutation. note a valid permutation has the same size as nums
        if(track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        //// backtrack
        for(int i = 0; i < nums.size(); ++i)
        {
            //// preorder edge, prune leaf, make selection
            if(path[i]) // used
                continue;
            // !path[i - 1] means 2' is in front of 2, so we prune this leaf to make sure 2 is in front of 2'
            if(i > 0 and nums[i] == nums[i - 1] and !path[i - 1])
                continue;
            track.push_back(nums[i]);
            path[i] = true;
            //// traverse
            backtrack(nums, track, path, res);
            //// postorder edge, revoke selection
            track.pop_back();
            path[i] = false;
        }
    }
};