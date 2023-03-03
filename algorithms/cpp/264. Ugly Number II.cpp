class Solution {
public:
    /** 
        dp
        
        def: 
            list of ugly numbers, in ascending order
        stf:
            1. find curMin 
            2. add curMin to dp
            3. update pointer, value of product of 2, 3, 5 if curMin is a product of any one of them
        bc:
            n <= 0, return false

        time O(n)
        space O(n)
    */
    int nthUglyNumber(int n) {
        //// bc
        if(n <= 0)
            return false;
        
        int p2 = 0, p3 = 0, p5 = 0; // pointer of 2, 3, 5. indicate v2, v3, v5 position in the list of product of 2, 3, 5 with uglyNumber
        int v2 = 1, v3 = 1, v5 = 1; // value of the next value in the list of product of 2, 3, 5 with uglyNumber
        vector<int> dp(n);    // list of ugly numbers, in ascending order
        //// dp
        for(int i = 0; i < n; ++i)
        {
            //// find curMin
            int curMin = min(v2, min(v3, v5));
            //// add curMin to dp
            dp[i] = curMin;
            //// update pointer, value of product of 2, 3, 5 if curMin is a product of any one of them
            if(curMin == v2)
            {
                v2 = dp[p2] * 2;
                ++p2;
            }
            if(curMin == v3)
            {
                v3 = dp[p3] * 3;
                ++p3;
            }
            if(curMin == v5)
            {
                v5 = dp[p5] * 5;
                ++p5;
            }
        }
        return dp[n - 1];
    }
};
