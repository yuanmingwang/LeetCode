class Solution {
    public:
        /** 
            Hash Table, String, Sliding Window
    
            The sliding window algorithm works like this:
                1.We use two pointers, left and right, in the string S, initializing left = right = 0. 
                  We call the index interval [left, right) a "window."
                
                2.We continuously increase the right pointer to expand the window [left, right) until the substring in the window meets the requirement (contains all characters in T).
    
                3.At this point, we stop increasing right and start increasing the left pointer to shrink the window [left, right) until the substring no longer meets the requirement (does not contain all characters in T). 
                  Each time we increase left, we update the result.
    
                4.Repeat steps 2 and 3 until right reaches the end of the string S.
    
            time O(n)
            space O(n)
        */
        string minWindow(string s, string t) {
            unordered_map<char, int> window, need;
            int left = 0, right = 0;
            // valid variable represents the number of characters in the window that meet the need conditions. 
            // If valid is equal to need.size, it means the window satisfies the conditions and completely covers the string T.
            int valid = 0;
            int res_start = 0, res_len = INT_MAX;   // we need to know the start and len to use s.substr()
    
            //// init need map. k = char in t, v = number of time it appears
            for(auto &c : t)
                ++need[c];
    
            while(right < s.size())
            {
                //// expand the window
                // c_right is the character to be moved into the window
                char c_right = s[right];
                right++;
    
                //// perform a series of updates to the data within the window
                if(need.contains(c_right))
                {
                    ++window[c_right];
                    // the # of char c_right in the window matches the # of c_right in need, all c_right have been matched, update valid
                    if(window[c_right] == need[c_right])
                        ++valid;
                }
    
                //// determine whether the left window needs to be shrinked
                while(valid == need.size()) // shrink the window only if all char in t have been included 
                {
                    //// update the minimum covering substring, res_start and res_len
                    int curr_len = right - left;
                    if(curr_len < res_len)
                    {
                        res_len = curr_len;
                        res_start = left;
                    }
    
                    //// shrink the window
                    // c_left is the character to be moved out of the window
                    char c_left = s[left];
                    ++left;
                    
                    //// perform a series of updates to the data within the window
                    if(need.contains(c_left))
                    {
                        if(window[c_left] == need[c_left])
                            --valid;
                        --window[c_left];
                    }
                }
            }
    
            //// return the minimum covering substring
            return res_len == INT_MAX ? "" : s.substr(res_start, res_len);
        }
    };