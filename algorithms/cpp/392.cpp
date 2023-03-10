class Solution {
public:
    /** 
        two pointers

        time O(n)
        space O(1)
    */
    bool isSubsequence(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();
        int i = 0, j = 0;
        
        while(i < size_s and j < size_t)
        {
            //// match, move pointer i
            if(s[i] == t[j])
                ++i;
            ++j;
        }
        //// i points to the end means we match all characters in s
        return i == size_s;
    }
};