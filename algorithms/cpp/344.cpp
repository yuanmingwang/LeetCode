class Solution {
    public:
        /** 
            Two Pointers, String
    
            time O(n)
            space O(1)
        */
        void reverseString(vector<char>& s) {
            // two pointers, one on the left and one on the right, move towards each other
            int left = 0, right = s.size() - 1;
            while(left < right)
            {
                // swap s[left] and s[right]
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                // move pointer towards each other
                ++left;
                --right;
            }
        }
    };