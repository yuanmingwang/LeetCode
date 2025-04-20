class Solution {
    public:
    //// 42. Trapping Rain Water
    /** 
        Two Pointers

        Approach #1: Two Pointers

        logic:
            To calculate how much amount of water the ith bar can trap, we need to look at the maximum height of the left bar and the maximum height of the right bar, then
                The water level can be formed at ith bar is: waterLevel = min(l_max[i], r_max[i])
                If waterLevel >= height[i] then ith bar can trap waterLevel - height[i] amount of water.
        
        note:
            1. How to decide to move left or move right?
                Move the lower side to get max result

        time O(N)
        space O(1)
    */
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int l_max  = 0, r_max = 0;
        int res = 0;
        while(left < right)
        {
            l_max = max(l_max, height[left]);   // max in range [0, left]
            r_max = max(r_max, height[right]);   // max in range [right, height.size() - 1]

            // the smaller one determines how much water it can hold
            if(l_max < r_max)
            {
                res += l_max - height[left];
                ++left;
            }
            else
            {
                res += r_max - height[right];
                --right;
            }
        }
        return res;
    }
};