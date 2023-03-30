class Solution {
public:
    /** 
        backtracking
        time O(2^n)
        space O(N)
    */
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        //// we sort the nums first. in the backtrack we prune the leaf if nums[i] == nums[i - 1]
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, track, res);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track, vector<vector<int>>& res)
    {
        //// preorder node, add current track to res
        res.push_back(track);

        //// backtrack
        for(int i = start; i < nums.size(); ++i)
        {
            //// prune the leaf if nums[i] == nums[i - 1]
            if(i > start and nums[i] == nums[i - 1])
                continue;
            //// preorder edge, make selection
            track.push_back(nums[i]);
            //// traverse
            backtrack(nums, i + 1, track, res);
            //// postorder edge, revoke selection
            track.pop_back();
        }
    }
};