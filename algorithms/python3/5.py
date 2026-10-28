class Solution:
    """ 
        5. Longest Palindromic Substring
        Two Pointers, String

        Approach : Expand Around Center
            A palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n - 1 such centers.
            There are two cases:
                1. The center of a palindrome is a single letter and such palindromes have odd number of letters (such as "aba"). This has n different center.
                2. The center of a palindrome is in between two letters and such palindromes have even number of letters (such as "abba"). This has n-1 different center.
            Therefore, there are total 2n - 1 centers

        time O(n^2): there are 2n - 1 centers to check, and expanding a palindrome around its center could take O(n) time, 
        space O(1)
    """
    def longestPalindrome(self, s: str) -> str:
        res = ""
        for i in range(len(s)):
            l = r = i
            ## check case 1. center is i
            s1 = self.palindrome(s, l, r)
            ## check case 2. center is between i and i + 1
            s2 = self.palindrome(s, l, r + 1)

            ## update res
            res = res if len(res) >= len(s1) else s1
            res = res if len(res) >= len(s2) else s2
        return res

    ## return the longgest palindrome whose mid point is l = r(odd) or between l and r(even)
    def palindrome(self, s: str, l: int, r: int) -> str:
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        ## now l + 1 is the start of the palindrome, r - 1 is the end of the palindrome
        return s[l+1:r]