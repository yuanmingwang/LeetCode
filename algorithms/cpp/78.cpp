class Solution {
public:
    /** 
        backtracking
        Subset (Combinations) (no repetition, no multiple-choice)

        time O(2^N) because there are 2^n subset for a given set, and our code just go throught every node once
        space O(N)
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
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
            //// preorder edge, make selection
            track.push_back(nums[i]);
            
            //// traverse
            backtrack(nums, i + 1, track, res);

            //// postorder edge, revoke selection
            track.pop_back();
        }
    }
};