class Solution {
public:
    /** 
        13. Roman to Integer
        Hash Table, String

        Intuition:
            Use a map of Roman characters to their integer values.
            
        Algorithm:
            1. Initialize hashtable, result = 0.
            2. Loop through the string:
            3. If current value < next value → subtract current.
                Else → add current.
            4.At the end, result contains the integer value.

        time O(n)
        space O(1)
    */
    int romanToInt(string s) {
        //// 1.
        unordered_map<char, int> umap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int res = 0;
        //// 2.
        int size = s.size();
        for (int i = 0; i < size; ++i)
        {
            int curr_i = umap[s[i]];
            int next_i = i + 1 < size ? umap[s[i + 1]] : 0;
            //// 3.
            if (curr_i < next_i)
                res -= curr_i;
            else
                res += curr_i;
        }
        return res;
    }
};