class Solution {
public:
    /** 
        Hash Table

        time O(N)
        space O(N)
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;   // k = num, v = index of num in nums
        for(int i = 0; i < nums.size(); ++i)
        {
            int need = target - nums[i];    // number we need to get target
            if(umap.find(need) != umap.end())
                return {i, umap[need]};
            umap[nums[i]] = i;
        }
        return {};
    }
};