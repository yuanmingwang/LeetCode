class Solution {
public:
    /** 11. Container With Most Water
        Two Pointers

        logic:
            Similar to the rain catching problem, the height is determined by the smaller one between height[left] and height[right].
            Use the left and right pointers to shrink the rectangle between [left, right] from both ends to the center, 
            and calculate the area of the rectangle between [left, right] while shrinking it, and take the largest area value to be the answer.
        
        note:
            area = min(height[left], height[right]) * (right - left)
            Move the lower side to get max result

        time O(N)
        space O(1)
    */
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;

        while(left < right)
        {
            //// calculate & update area
            int area = min(height[left], height[right]) * (right - left);
            res = max(res, area);
            //// shrink the rectangle
            if(height[left] < height[right])
                ++left;
            else
                --right;
        }
        return res;
    }
};