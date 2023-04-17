class Solution {
public:
    /** 
        Backtracking
            Similar to 131. Palindrome Partitioning (https://leetcode.com/problems/palindrome-partitioning/description/)
            Only need to modify IsValid() and track. we have only 4 element in track here because the ip address is *.*.*.*

        time O(1) / O(n) if we use s.substr()
            What we are trying to do here is to partition the input string into 4 parts with 3 cuts. 
            There are C(n, 3) ways to cut the string into 4 parts. In that sense, the time complexity is O(n^3). 
            On second thought, however, because we are doing backtracking and removing lots of unnecessary checking
            we are only checking three possibilities for each part (it has to be [0,255]), it becomes 3^4, which is just a constant, so it becomes O(1)
        space O(1)
    */
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> track;   // track[0-3] store the 4 sections of the ip address
        backtrack(s, 0, track, res);
        return res;
    }

    void backtrack(string& s, int start, vector<string>& track, vector<string>& res)
    {
        //// bc
        // reach the end
        if(start == s.size())
        {
            // find a valid ip address
            if(track.size() == 4)
            {
                // construct the ip string from track
                string ip = track[0];
                for(int i = 1; i < track.size(); ++i)
                    ip = ip + '.' + track[i];
                res.push_back(ip);
            }
            return;
        }
        //// backtrack
        for(int i = start; i < s.size(); ++i)
        {
            //// preorder edge
            string subStr = s.substr(start, i - start + 1);
            // check if s[start .. i] is a valid ip address
            if(!isValid(subStr))
                continue;
            // make selection
            track.push_back(subStr);
            
            //// traverse
            backtrack(s, i + 1, track, res);

            //// postorder edge
            // revoke selection
            track.pop_back();
        }
    }

    //// return true if s is a valid ip integer
    bool isValid(string& s)
    {
        // integer is between 0 and 255
        if(s.size() < 0 or s.size() > 3)
            return false;
        // cannot have leading zeros
        if(s.size() > 1 and s[0] == '0')
            return false;
        // // not a digit
        // for(auto& c : s)
        // {
        //     if(!isdigit(c))
        //         return false;
        // }
        if(stoi(s) > 255)
            return false;
        return true;
    }
};