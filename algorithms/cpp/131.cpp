class Solution {
public:
    /** 
        Backtracking

        time O(2^N * N)
            2^n backtrack calls and n for each backtrack call
            there are 2^n subset for a set. we are making 1 backtrack call for every subset. 
            for each backtrack calls, we need O(N) to check palindrome and O(N) for substr
        space O(2^N * N)
            total 2^N posible subset and maximum n length for each subset.
            for example, 'a' * N will give 2^N subset with maximum length N
    */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> track;
        backtrack(s, 0, track, res);
        return res;
    }

    //// check palindrome for partition s[start .. s.size() - 1]
    void backtrack(string& s, int start, vector<string>& track, vector<vector<string>>& res)
    {
        //// preorder node. bc. reach the end, find a match
        if(start == s.size())
        {
            res.push_back(track);
            return;
        }
        //// backtrack
        for(int i = start; i < s.size(); ++i)
        {
            //// preorder edge
            // check if s[start .. i] is palindrome
            if(!isPalindrome(s, start, i))  // not a palindrome, continue
                continue;
            // make selection
            track.push_back(s.substr(start, i - start + 1));

            //// traverse
            backtrack(s, i + 1, track, res);    // s[start .. i] is done, need to check the s[i + 1 .. s.size() - 1]

            //// postorder edge, backtrack
            track.pop_back();
        }
    }

    //// return true if s[left .. right] is a palindrome
    // two pointer
    bool isPalindrome(string& s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};