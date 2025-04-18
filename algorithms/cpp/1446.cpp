class Solution {
    public:
    //// 1446. Consecutive Characters
    /** 
        String

        Approach #1: One Pass
        
        time O(n)
        space O(1)
    */
    int maxPower(string s) {
        int res = 0;
        int curr_count = 0;
        char prev = ' ';
        for(auto& c : s)
        {

            if(c == prev)
            {
                ++curr_count;
                // res = max(res, ++curr_count);
            }
            else
            {
                prev = c;
                // reset to 1 because prev now count for 1 consecutive characters
                curr_count = 1;
            }
            // need to update here because we can have string like "tourist" which has no consecutive characters
            res = max(res, curr_count);
        }
        return res;
    }
};