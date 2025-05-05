class Solution {
    public:
        //// 1598. Crawler Log Folder
        //// Array, String, Stack
        /** 
            Approach #1: Counter
    
            Intuition:
                To solve this problem, we need to track the user's position within the folder structure relative to the main folder. 
                We can achieve this using a numerical counter that represents the depth of the current folder.
            
            Algorithm:
                1. We initialize the counter to 0, representing the main folder.
                2. When we encounter "../", we decrease the counter by 1 to move up a level. If the counter is already at 0, it remains at 0 because we can't move above the main folder.
                3. If we enter a child folder ("x/"), we increase the counter by 1 to go deeper into the folder structure.
                4. "./" operations do not change the counter since they keep us in the current folder.
                
    
            time O(n)
            space O(1)
        */
        int minOperations(vector<string>& logs) {
            string parent = "../";
            string remain = "./";
            // represents the depth of the current folder
            int res = 0;
    
            for(auto &s : logs)
            {
                //// 2.
                if(s == parent)
                    res = max(0, res - 1);
                //// 3.
                else if(s != remain)
                    ++res;
                //// 4. ignore "./"
            }
            return res;
        }
    };