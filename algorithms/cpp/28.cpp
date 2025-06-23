class Solution {
public:
    /** 28. Find the Index of the First Occurrence in a String
        Two Pointers

        Approach #1: Brute-Force

        time O(n*m). m = needle.size(), n = haystack.size()
        space O(1)
    */
    int strStr(string haystack, string needle) {
        int haystack_length = haystack.size();
        int needle_length = needle.size();
        int p1 = 0; // haystack pointer
        for(; p1 <= haystack_length - needle_length; ++p1)
        {
            int p2 = 0; // needle pointer
            for(; p2 < needle_length; ++p2)
            {
                //// find an unmatched char. break
                if(haystack[p1 + p2] != needle[p2])
                    break;
            }
            //// check if we find a match. if matched, p1 points to the start of the matched string now
            if(p2 == needle_length)
                return p1;
        }
        return -1;
    }

/** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
    /** 28. Find the Index of the First Occurrence in a String
        Two Pointers, KMP

        Approach #2: KMP

        definition:
            1. LPS is the Longest Proper Prefix which is also a Suffix. A proper prefix is a prefix that doesn’t include whole string. 
            For example, prefixes of “abc” are “”, “a”, “ab” and “abc” but proper prefixes are “”, “a” and “ab” only. Suffixes of the string are “”, “c”, “bc”, and “abc”.
            
            2. lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. where pat = pattern = needle in this question

        logic to construct lps:
            lps[0] is always 0 since a string of length one has no non-empty proper prefix. 
            We store the value of the previous LPS in a variable len, initialized to 0. 
            As we traverse the pattern, we compare the current character at index i, with the character at index len.

            1. Case 1 – pat[i] = pat[len]: 
                this means that we can simply extend the LPS at the previous index, so increment len by 1 and store its value at lps[i].

            2. Case 2 – pat[i] != pat[len] and len = 0: 
                it means that there were no matching characters earlier and the current characters are also not matching, so lps[i] = 0.

            3. Case 3 – pat[i] != pat[len] and len > 0: 
                it means that we can’t extend the LPS at index i-1. However, there may be a smaller prefix that matches the suffix ending at i. 
                To find this, we look for a smaller suffix of pat[i-len…i-1] that is also a proper prefix of pat. We then attempt to match pat[i] with the next character of this prefix. 
                If there is a match, pat[i] = length of that matching prefix. Since lps[i-1] equals len, we know that pat[0…len-1] is the same as pat[i-len…i-1]. 
                Thus, rather than searching through pat[i-len…i-1], we can use lps[len – 1] to update len, since that part of the pattern has already been matched. 
        
        logic of strstr using lps:
            create two pointers, ont cursor in haystack and another cursor in needle

            1. If characters match, haystack[i] == needle[j]: 
                move both pointers forward
            2. If there is a mismatch, and cursor in needle == 0: 
                move cursor in haystack directly because there is no match for char in lps
            3. If there is a mismatch, and cursor in needle > 0: 
                Use lps value of previous index to avoid redundant comparisons

        check: 
            1. https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm# for kmp
            2. https://www.cnblogs.com/zhaodongge/p/15004032.html for Brute-Force, KMP, Rabin-Karp
            3. video: https://www.bilibili.com/video/BV1AY4y157yL/?spm_id_from=333.337.search-card.all.click&vd_source=4c7356a012c4f82a5c65a3349796df32

        time O(m + n). O(m) to construct KMP prefix (or next) table, O(n) for search. m = needle.size(), n = haystack.size()
        space O(1)
    */
    int strStr(string haystack, string needle) {
        int haystack_length = haystack.size();
        int needle_length = needle.size();
        
        int i = 0;  // cursor in haystack
        int j = 0;  // cursor in needle
        vector<int> lps = kmpPreProcess(needle);
        while(i < haystack_length)
        {
            //// 1.
            if(haystack[i] == needle[j])
            {
                ++i;
                ++j;

                //// find a match
                if(j == needle_length)
                    return i - needle_length;
            }
            else
            {   //// 2.
                if(j == 0)
                {
                    ++i;
                }
                //// 3.
                else
                {
                    j = lps[j - 1];
                }
            }
        }
        return -1;
    }

    //// construct kmp prefix table. note needle is the pat above
    vector<int> kmpPreProcess(string needle) {
        int needle_length = needle.size();
        vector<int> lps(needle_length, 0);

        int i = 1; // cursor in needle. points to the end of the suffix
        int prefix_len = 0; // curr common prefix and suffix length. points to the end of the prefix

        while(i < needle_length)
        {
            //// 1.
            if(needle[i] == needle[prefix_len])
            {
                ++prefix_len;
                lps[i] = prefix_len;
                ++i;
            }
            else
            {
                //// 2.
                if(prefix_len == 0)
                {
                    lps[i] = 0;
                    ++i;
                }
                //// 3.
                else
                {
                    prefix_len = lps[prefix_len - 1];
                }
            }
        }
        return lps;
    }
};