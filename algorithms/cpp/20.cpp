class Solution {
    public:
        /** 20. Valid Parentheses
            String, Stack
            This is a classic problem involving bracket. Such problems can generally be solved using a stack. 
            The approach is: 
                1. when encountering an open bracket, push it into the stack; 
                2. when encountering a close bracket, pop the top open bracket from the stack to check if it matches with the close bracket.
            
            time O(n)
            space O(n)
        */
        bool isValid(string s) {
            // store the open bracket
            stack<char> st;
            // match the close bracket to open bracket
            unordered_map<char, char> umap {
                {')', '('},
                {'}', '{'},
                {']', '['},
            };
    
            for(auto &ch : s)
            {
                //// open brackets
                if(not umap.contains(ch))
                {
                    st.push(ch);
                }
                //// close bracket
                else
                {
                    // no open bracket or does not match the most recent open bracket
                    if(st.empty() or umap[ch] != st.top())
                        return false;
                    // matched, pop the open bracket
                    else
                        st.pop();
                }
            }
            //check if all open bracket have been matched. empty stack means all brackets have been matched, return true
            return st.empty();
        }
    };