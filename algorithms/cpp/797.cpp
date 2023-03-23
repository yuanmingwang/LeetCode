class Solution {
public:
    //// DFS, recursive, time = O(N) to O(N^2)
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, res, path, 0);
        return res;
    }
    
    //// dfs
    // res: list of valid paths
    // path: curr path
    // cur: current node
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int cur)
    {
        //// add curr node to the curr path
        path.push_back(cur);
        
        //// reach the end, curr path is a valid path
        if(cur == graph.size() - 1)
        {
            res.push_back(path);
        }
        
        //// enter the cur node
        //// recursively check its children
        for(auto &child : graph[cur])
        {
            dfs(graph, res, path, child);
        }
        //// leave the cur node
        path.pop_back();
    }
    
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         int size = graph.size();
//         vector<vector<int>> res = {};
//         //// edge case
//         if(size == 0)
//             return res;
        
//         //// init dfs
//         stack<vector<vector<int>>> s;   // s stores the curr path {node, {path}}
//         s.push({0, {0}});   // path to node 0 is {0}
//         vector<vector<int>> cur_path;
//         //// dfs
//         while(!s.empty())
//         {
//             //// get curr path
//             cur_path = s.top();
//             s.pop();
//             //// check if curr node is the end
//             if()
//         }
        
//         return res;
//     }
};