class Solution {
    public:
        /** 
            Hash Table, Two Pointers, String, Sliding Window
    
            Similar approach & sliding Window framework as 76.Minimum Window Substring.
            Check it for detailed explanation
    
            time O(n)
            space O(n)
        */
        bool checkInclusion(string s1, string s2) {
            unordered_map<char, int> window, need;
            int left = 0, right = 0;
            int valid = 0;
    
            //// init need map. k = char in s1, v = number of time it appears
            for(auto &c : s1)
                ++need[c];
    
            while(right < s2.size())
            {
                //// expand the window
                char c_right = s2[right];
                ++right;
    
                //// perform a series of updates to the data within the window
                if(need.contains(c_right))
                {
                    ++window[c_right];
                    if(window[c_right] == need[c_right])
                        ++valid;
                }
    
                //// determine whether the left window needs to be shrinked
                // shrink the window if its size is larger than or equal s1's size 
                // because we want to check the situtation where the window size equals to the s1.size()
                while(right - left >= s1.size())
                {
                    //// check if a valid substring is found
                    if(valid == need.size())
                        return true;
    
                    //// shrink the window
                    char c_left = s2[left];
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
            //// return. if we reach here, meaning we did not find a valid permutation
            return false;
        }
    };