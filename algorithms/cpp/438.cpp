class Solution {
    public:
        /** 
            Hash Table, String, Sliding Window
    
            Similar approach & sliding Window framework as 76.Minimum Window Substring and 567. Permutation in String
            Check them for detailed explanation.
    
            time O(n)
            space O(n)
        */
        vector<int> findAnagrams(string s, string p) {
            unordered_map<char, int> window, need;
            int left = 0, right = 0;
            int valid = 0;
            vector<int> res;
    
            //// init need map. k = char in s1, v = number of time it appears
            for(auto &c : p)
                ++need[c];
    
            while(right < s.size())
            {
                //// expand the window
                char c_right = s[right];
                ++right;
    
                //// perform a series of updates to the data within the window
                if(need.contains(c_right))
                {
                    ++window[c_right];
                    if(window[c_right] == need[c_right])
                        ++valid;
                }
    
                //// determine whether the left window needs to be shrinked
                while(right - left >= p.size())
                {
                    //// check if a valid substring is found
                    if(valid == need.size())
                        res.push_back(left);
    
                    //// shrink the window
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
            //// return res
            return res;
        }
    };