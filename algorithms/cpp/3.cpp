class Solution {
public:
    /** 3. Longest Substring Without Repeating Characters
        Hash Table, String, Sliding Window
        Integer Array

        time O(n)
        space O(1)
    */
    int lengthOfLongestSubstring(string s) {
        vector<int> vCharIndex(128, -1); // vCharIndex[i] = the last seen position of i. i is the ascii value of the curr char
        int res = 0;
        int length = s.length();
        int left = 0, right;   // left and right boundary of the sliding window

        //// iterate over string s
        for(right = 0; right < length; ++right)
        {
            int curr_char_ascii = s[right];
            int curr_char_last_position = vCharIndex[curr_char_ascii];
            
            if(curr_char_last_position >= left) // find a repeating char
            {
                // update the sliding window's left boundary to the next of the last seen position of curr char to find a new substring without repeating characters
                left = curr_char_last_position + 1;
            }
            //// update the sliding window right boundary
            vCharIndex[curr_char_ascii] = right;
            //// update max length
            res = max(res, right - left + 1);
        }

        return res;
    }


/** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
    /** 3. Longest Substring Without Repeating Characters
        Hash Table, String, Sliding Window
        Unordered Map

        time O(n)
        space O(1)
    */
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int res = 0, left = 0, right = 0;
        
        while(right < s.size())
        {
            char c_right = s[right];
            ++right;    // expend window
            ++window[c_right];  // update window
            
            // shrink window if c_right is a repeated char
            while(window[c_right] > 1)
            {
                char c_left = s[left];
                --window[c_left];    // remove the left char from the map 
                ++left; // shrink window
            }
            // now, there should be no repetition
            // update res
            res = max(res, right - left);
        }
        return res;
    }

/** 3.---------------------------------------------------------------------------------------------------------------------------------------- **/
    /** 3. Longest Substring Without Repeating Characters
        Hash Table, String, Sliding Window
        Unordered Set
        
        time O(n)
        space O(1)
    */
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        
        int left = 0, right = 0, n = s.size(), result = 0;
        
        while (left < n && right < n)
        {
            // if the right element is not in the set
            if (set.find(s[right]) == set.end())
            {
                // insert element into set
                set.insert(s[right]);
                // move right pointer to the next position
                right++;
                // update result if new length is larger
                result = max(result, right - left);
            }
            // if the right element is in the set, 
            // keep moving the left pointer until there is no repeated char
            else
            {
                // remove the left char
                set.erase(s[left]);
                // move left pointer to the next position
                left++;
            }
        }
        return result;
    }
};