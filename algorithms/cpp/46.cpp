class Solution {
public:
    /** 46. Permutations
        backtracking
        Permutations (no repetition, no multiple-choice)

        time O(N! * N)
        space O(N)
    */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track = {};
        vector<bool> path(nums.size(), false);

        backtracking(nums, track, path, res);
        return res;
    }

private:
    //// track: cur track
    //// path: cur path
    void backtracking(vector<int>& nums, vector<int>& track, vector<bool>& path, vector<vector<int>>& res)
    {
        if(track.size() == nums.size()) // found a track
        {
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(path[i]) // used
                continue;

            //// make selection
            track.push_back(nums[i]);
            path[i] = true;

            //// traverse
            backtracking(nums, track, path, res);

            //// revoke selection
            track.pop_back();
            path[i] = false;
        }
    }
};

class Solution {
public:
    /** 
        backtracking swaping element (so we dont need track and path/used vector)
        time O(N!)
        space O(N)
    */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        backtracking(nums, res, 0);
        return res;
    }

private:
    //// left: the begin index of the cur track
    void backtracking(vector<int>& nums, vector<vector<int>>& res, int left)
    {
        if(left == nums.size()) // found a track
        {
            res.push_back(nums);
            return;
        }
        //// swap left and i. lets say we have ABC, left = 0. we then have swap(A, A) -> ABC, swap(A, B) = BAC, swap(A, C) = CBA. and we keep going..
        for(int i = left; i < nums.size(); ++i)
        {
            //// make selection
            swap(nums[left], nums[i]);

            //// traverse
            backtracking(nums, res, left + 1);

            //// revoke selection
            swap(nums[left], nums[i]);
        }
    }
};