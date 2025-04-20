class Solution {
    public:
    //// 125. Valid Palindrome
    /** 
        Two Pointers, String

        time O(n)
        space O(1)
    */
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            //// skip non alphanumeric character
            if(!isalnum(s[left]))
            {
                ++left;
                continue;
            }
            if(!isalnum(s[right]))
            {
                --right;
                continue;
            }

            //// check palindrome
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            ++left;
            --right;
        }
        return true;
    }
};