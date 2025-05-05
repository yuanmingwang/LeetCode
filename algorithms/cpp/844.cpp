class Solution {
    public:
        //// 844. Backspace String Compare
        //// Two Pointers, String, Stack
        /** 
            Approach #1: Two Pointers
    
            Intuition:
                When writing a character, it may or may not be part of the final string depending on how many backspace keystrokes occur in the future.
                If instead we iterate through the string in reverse, then we will know how many backspace characters we have seen, and therefore whether the result includes our character.
            
            Algorithm:
                Iterate through the string in reverse. 
                1. If we see a backspace character, the next non-backspace character is skipped. 
                2. If a character isn't skipped, it is part of the final answer.
    
            time O(m + n). m = s.size(), n = t.size()
            space O(1)
        */
        bool backspaceCompare(string s, string t) {
            char c_backspacing = '#';
            int p_s = s.size() - 1;
            int p_t = t.size() - 1;
            int skip_s = 0;
            int skip_t = 0;
    
            while(p_s >= 0 or p_t >= 0)
            {
                //// find positioin of next possible char in s
                while(p_s >= 0)
                {
                    // match backspacing, mark in the skip_s and move on
                    if(s[p_s] == c_backspacing)
                    {
                        --p_s;
                        ++skip_s;
                    }
                    // not match backspacing, skip char based on the number of backspacing we met which stored in skip_s
                    else
                    {
                        if(skip_s > 0)
                        {
                            --p_s;
                            --skip_s;
                        }
                        // finish skiping, now p_s points to the valid char
                        else
                            break;
                    }
                }
                //// find positioin of next possible char in t, same as above
                while(p_t >= 0)
                {
                    if(t[p_t] == c_backspacing)
                    {
                        --p_t;
                        ++skip_t;
                    }
                    else
                    {
                        if(skip_t > 0)
                        {
                            --p_t;
                            --skip_t;
                        }
                        else
                            break;
                    }
                }
    
                //// now, p_s and p_t both point to the valid char
    
                // if expect to compare char vs nothing
                if((p_s >= 0) != (p_t >= 0))
                    return false;
    
                // if two characters are different
                if(p_s >= 0 and p_t >= 0 and s[p_s] != t[p_t])
                    return false;
    
                --p_s;
                --p_t;
            }
    
            return true;
        }


        /** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
    public:
        //// 844. Backspace String Compare
        //// Two Pointers, String, Stack
        /** 
            Approach #2: Stack

            Intuition:
                Let's individually build the result of each string (build(S) and build(T)), then compare if they are equal.
            
            Algorithm:
                To build the result of a string build(S), we'll use a stack based approach, simulating the result of each keystroke.

            time O(m + n). m = s.size(), n = t.size()
            space O(m + n)
        */
        bool backspaceCompare(string s, string t) {
            return build(s) == build(t);
        }

    private:
        char c_backspacing = '#';

        //// return the final string after backspacing
        string build(string s) {
            //// build stack containing all valid characters
            stack<char> stack;
            for(auto& c : s)
            {
                if(c != c_backspacing)
                    stack.push(c);
                else if(!stack.empty())
                    stack.pop();
            }

            //// construct the result string
            string res;
            while(!stack.empty())
            {
                // reconstruct the res by reversing the stack
                res = stack.top() + res;
                stack.pop();
            }
            
            return res;
        }


        /** 3.---------------------------------------------------------------------------------------------------------------------------------------- **/
    public:
        /** 
            Approach #3: Stack, worser compare to approach #1 and #2. build() return stack instead of string 

            Intuition:
                Let's individually build the result of each string (build(S) and build(T)), then compare if they are equal.
            
            Algorithm:
                To build the result of a string build(S), we'll use a stack based approach, simulating the result of each keystroke.

            time O(m + n). m = s.size(), n = t.size()
            space O(m + n)
        */
        bool backspaceCompare(string s, string t) {
            stack<char> stack_s = build(s);
            stack<char> stack_t = build(t);

            while(not stack_s.empty() and not stack_t.empty())
            {
                char c_s = stack_s.top();
                char c_t = stack_t.top();

                if(c_s != c_t)
                    return false;
                
                stack_s.pop();
                stack_t.pop();
            }

            if(not stack_s.empty() or not stack_t.empty())
                return false;

            return true;
        }

    private:
        char c_backspacing = '#';

        stack<char> build(string s) {
            stack<char> stack;
            //// build stack containing all valid characters
            for(auto& c : s)
            {
                if(c != c_backspacing)
                    stack.push(c);
                else if(not stack.empty())
                    stack.pop();
            }

            return stack;
        }
    };
