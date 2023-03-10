class Solution {
public:
    /** 
        Binary search & Hash Table & two pointers

        time O(mlogn), n = s.size(), n = words.size()
        space O(m)
    */
    int numMatchingSubseq(string s, vector<string>& words) {
        int size = s.size();
        int res = 0;
        
        unordered_map<char, vector<int>> umap;  // k = char, v = list of index that char is in s
        //// build hash table
        for(int i = 0; i < size; ++i)
        {
            umap[s[i]].push_back(i);
        }

        // for(auto& i : s)
        // {
        //     cout<<i<<": ";
        //     for(auto& j : umap[i])
        //         cout<<j<<" ";
        //     cout<<endl;
        // }

        //// check every words using binary search, similar to 392. Is Subsequence https://leetcode.com/problems/is-subsequence/description/
        for(auto& word : words)
        {
            int i = 0;  // pointer of word in words
            int j = 0;  // pointer of s, we need to pick char at or starting from this index
            
            // cout<<"word = "<<word<<endl;
            //// for each char in word
            for(; i < word.size(); ++i)
            {
                auto& c = word[i];
                //// we don't need to check this because it will be an empty vector if it does not exist
                // //// c does not exist in s
                // if(umap.find(c) == umap.end())
                //     break;
                auto& v = umap[c];
                int left = left_bound(v, j);   // index of the next (c's pos in s) in v
                //// next does not exist
                if(left == -1)
                    break;
                j = v[left] + 1;    // index of the next c in s

                // cout<<"c = "<<c<<", left = "<<left<<", i = "<<i<<", j = "<<j<<endl;
            }
            if(i == word.size())
                ++res;
        }
        return res;
    }

    //// binary search that find the left bound of target in v
    // note that the binary search will return the smallest number that are larger than target in v if the target is not found
    // hence, we can use this to find the next index of the char that is larger than target
    int left_bound(vector<int>& v, int target)
    {
        int size = v.size();
        int left = 0, right = size - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            //// target is in the right half
            if(v[mid] < target) 
                left = mid + 1;
            //// target is in the left half
            else if(v[mid > target])
                right = mid - 1;
            //// find the target, try to go left and search the left bound
            else
                right = mid - 1;
        }
        //// all val in v is smaller than target
        if(left >= size)
            return -1;
        //// if we find the target, return the index
        // return v[left] == target ? left : -1;
        //// here we ant to return the smallest number that are larger than target, so we just return left directly
        return left;
    }
};