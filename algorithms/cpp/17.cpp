class Solution {
public:
    /** 
        backtracking
        Combinations (Subset) (no repetition, no multiple-choice)

        time O(4^N * N), 4^N for recursion (there are at most 4 digits in each map), N for copying track into res at res.push_back()
        space O(N)
    */

    const vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};    // digit to string

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        
        vector<string> res;
        string track;
        backtrack(digits, 0, track, res);
        return res;
    }

    //// actually we don't need start. start = track.size(). I keep it here for clarity
    void backtrack(string& digits, int start, string& track, vector<string>& res)
    {
        //// preorder node, add res
        if(track.size() == digits.size())
        {
            res.push_back(track);
            return;
        }
        //// backtrack
        // find string that maps the cur digit
        int digit = digits[start] - '0';
        string curString = map[digit];
        for(int i = 0; i < curString.size(); ++i)
        {
            //// preorder edge, make selection
            track.push_back(curString[i]);
            //// traverse
            backtrack(digits, start + 1, track, res);
            //// postorder edge, revoke selection
            track.pop_back();
        }
    }
};