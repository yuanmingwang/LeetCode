class Solution {
public:
    /** 
        Two Pointers, convert int to string

        time O(N)
        space O(1)
    */
    bool isPalindrome(int x) {
        string s = to_string(x);
        int left = 0, right = s.size() - 1;
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