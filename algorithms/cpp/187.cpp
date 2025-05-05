class Solution {
    public:
        //// 187. Repeated DNA Sequences
        //// Hash Table, String, Sliding Window, Rabin-Karp
        /** 
            Approach #1: Hash Table
    
            Intuition:
                Encountering this problem, the first intuition is to track the frequency of every possible 10-letter-long substring within the larger DNA string. 
                To efficiently look up these sequences, a HashTable (Python's Counter dictionary can be used here for convenience) is a natural choice because it allows insertions and lookups in constant time, assuming a good hash distribution.
            
            Algorithm:
                1. We want to iterate over the sequence only once and keep track of every 10-letter sequence as we go. This is a sliding window problem.
                2. Each time we encounter a new 10-letter sequence, we add it to the HashTable. If the sequence already exists in the table, we increment its count.
                3. Instead of waiting until the end to find out which sequences have occurred more than once, we can check the count as we go. 
                    If a sequence's count reaches 2, we add it to the answer list. We only need to do this once per sequence because the problem asks for sequences that occur 'more than once,' not the specific number of times they occur.
                4. When a sequence's count exceeds 2, we don't need to do anything more with it, so we can ignore it. This avoids adding duplicates to our results list and keeps the operation more efficient.
                5. Finally, we return the list of repeating 10-letter sequences.
                
    
            time O(n * l), n = s.size(), l = 10 in this problem because we are find a 10-letter sequences
            space O(n)
        */
        vector<string> findRepeatedDnaSequences(string s) {
            // k = sequence, v = count
            unordered_map<string, int> umap_sequence_count;
            // store the resulting repeated sequences
            vector<string> res;
            // the number of possible starting indices for 10-letter sequences
            int possible_start_indice = s.size() - 9;
    
            //// Loop through the string to examine all possible 10-letter sequences
            for(int i = 0; i < possible_start_indice; ++i)
            {
                //// Extract a 10-letter substring starting at index i
                string sequence = s.substr(i, 10);
    
                //// Increment the count for this particular sequence
                ++umap_sequence_count[sequence];
    
                //// find a repeated sequence, add it to the res
                if(umap_sequence_count[sequence] == 2)
                {
                    res.push_back(sequence);
                }
            }
    
            return res;
        }

        /** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
        //// 187. Repeated DNA Sequences
        //// Hash Table, String, Sliding Window, Rabin-Karp
        /** 
            Approach #1: Rabin-Karp, Sliding Window
    
            Intuition:
                
            
            Algorithm:
                

            Check: 
                1. https://blog.csdn.net/qq_44807756/article/details/130035650
    
            time O(n)
            space O(n)
        */
        vector<string> findRepeatedDnaSequences(string s) {
            unordered_map<char, int> dict = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};   // convert char to int
            unordered_set<int> seen;    // store the seen value
            unordered_set<string> res;  // store the duplicate value

            int base = 4;   // 4 series of nucleotides
            int length = 10;    // 10-letter-long sequences(substrings) 
            int base_pow_length = (int) pow(base, length - 1);  // use to remove the left most char / digit of the window
            int window = 0;    // curr window hash number
            int left = 0, right = 0;

            while(right < s.size())
            {
                //// expand window
                window = window * base + dict[s[right]];   // add new digit to the right of the window
                ++right;
                
                // shrink window if the window size is the length of the required string (10)
                if(right - left == length)
                {
                    if(seen.count(window))  // repeated value found
                    {
                        res.insert(s.substr(left, right - left));
                    }
                    else    // new value, add to seen
                    {
                        seen.insert(window);
                    }
                    // shrink window
                    window = window - dict[s[left]] * base_pow_length;  // remove the left most char
                    ++left;
                }
            }
            return vector<string>(res.begin(), res.end());
        }
    };