class Solution {
    public:
        //// 151. Reverse Words in a String
        //// Two Pointers, String
        /** 
            Approach #1: Two Pointers
    
            Intuition:
                1. reverse the entire string first
                2. reverse each word of the reversed string
                3. remove the space before reversing the string
                ex: 
                    s = "hello world yuanming"
                    1. s = "gnimnauy dlrow olleh"
                    2. s = "yuanming world hello"
            
            Algorithm:
                1. Reverse the whole string using two pointers or std::reverse()
                2. Then we iterate characters in string s, fill found word into s then reverse it, word by word.
                    Let l keep the starting index of the current word, r keep the next index for filling the current word.
                    Reverse the current word, which is s[l..r-1]
                    Set space character for character s[r] if r < s.size()
                3. Finally, resize the string s to remove redundant chars.
    
            time O(n)
            space O(1)
        */
        string reverseWords(string s) {
            char space = ' ';
            int size = s.size();
            int iterator_old = 0;   // iterator that uses to iterate over the original string
            int iterator_new = 0;   // iterator that uses to construct the resulting string
            
            //// 1. reverse the whole string
            reverse(s.begin(), s.end());
    
            //// 2. reverse word by word
            while(iterator_old < size)
            {
                //// Find the starting pos of the next word
                while(iterator_old < size and s[iterator_old] == space)
                    ++iterator_old;
                
                //// Add a space if it is not the first or the last word
                if(iterator_old < size and iterator_new > 0)
                {
                    s[iterator_new] = space;
                    ++iterator_new;
                }
    
                //// Assign the current word to the new position and Find ending pos of the current word
                int start_index = iterator_new;
                while(iterator_old < size and s[iterator_old] != space)
                {
                    s[iterator_new] = s[iterator_old];
                    ++iterator_new;
                    ++iterator_old;
                }
                // now, iterator_new points to the last char of the current word
    
                //// reverse the current word
                reverse(s.begin() + start_index, s.begin() + iterator_new);
            }
    
            //// 3. resize
            s.resize(iterator_new);
            return s;
        }
    };