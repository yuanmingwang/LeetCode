class Solution {
public:
    /** 
        dp, iteration, btm up

        def: 
            dp[i][j] = the cheapest price of using j steps/edges/flights to get to node i from the src

        stf:
            1.  for(flight : flights)
                dp[flight[1]][j] = min(dp[flight[1]][j], dp[flight[0]][j - 1] + flight[2])
                dp[to][j] = min(curMin price, dp[from][j - 1] + prices)
        bc:
            dp[src][..] = 0 because src to src is 0
            dp[..][..] = INT_MAX because we are finding the min
            
        res:
            dp[dst][k + 1]

        time O(n * k)
        space O(n * k)
    */
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<int>> dp(n, vector<int>(k + 2, INT_MAX));
        //// bc
        for(int j = 0; j < k + 2; ++j)
            dp[src][j] = 0;
        //// dp
        for(int j = 1; j < k + 2; ++j)
        {
            for(auto& flight : flights)
            {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                //// can not arrive from in j - 1 steps. prevent int overflow
                if(dp[from][j - 1] == INT_MAX)
                    continue;
                //// 1.
                dp[to][j] = min(dp[to][j], dp[from][j - 1] + price);
            }
        }
        // for(auto &i : dp)
        // {
        //     for(auto &j : i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        return dp[dst][k + 1] == INT_MAX ? -1 : dp[dst][k + 1];
    }
    
};