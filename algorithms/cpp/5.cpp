class Solution {
    public:
        /** 
            Two Pointers, String

            Approach : Expand Around Center
            A palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n - 1 such centers.
            There are two cases:
                1. The center of a palindrome is a single letter and such palindromes have odd number of letters (such as "aba"). This has n different center.
                2. The center of a palindrome is in between two letters and such palindromes have even number of letters (such as "abba"). This has n-1 different center.
            Therefore, there are total 2n - 1 centers

            time O(n^2): there are 2n - 1 centers to check, and expanding a palindrome around its center could take O(n) time, 
            space O(1)
        */
       
        string longestPalindrome(string s) {
            string res = "";
    
            for(int i = 0; i < s.size(); ++i)
            {
                int l = i, r = i;
                //// check case 1. center is i
                string odd = palindrome(s, l, r);
                //// check case 2. center is between i and i + 1
                string even = palindrome(s, l, r + 1);
    
                //// update res
                res = odd.size() > res.size() ? odd : res;
                res = even.size() > res.size() ? even : res;
            }
    
            return res;
        }
    
        //// return the longgest palindrome whose mid point is l = r(odd) or between l and r(even)
        string palindrome(const string &s, int l, int r)
        {
            while(0 <= l and r < s.size() and s[l] == s[r])
            {
                --l;
                ++r;
            }
            // now l + 1 is the start of the palindrome, r - 1 is the end of the palindrome
            return s.substr(l + 1, r - l - 1);
        }
    };