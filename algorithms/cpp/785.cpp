class Solution {
public:
    /** 
        recursion, dfs
        time O(E + V)
        space O(E + V)
    */
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);  // k: index of node, v: 0 = unvisited, 1 = color A, -1 = color B
        //// check each node recursively
        for(int i = 0; i < graph.size(); ++i)   // graph.size() = # of nodes in graph
        {
            //// only runs dfs if the node has not been visited
            if(colors[i] == 0 and !dfs(graph, colors, i, 1))
                return false;
        }
        return true;
    }

private:
    //// return false if there are two adjacent nodes have the same color in graph[i]
    // i: cur node
    // color: cur node color
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int i, int color)
    {
        colors[i] = color;
        //// check adjacent nodes
        for(auto& node : graph[i])
        {
            //// unvisited ndoe, set color
            if(colors[node] == 0)
            {
                if(!dfs(graph, colors, node, -color))
                    return false;
            }
            //// visited node, check color
            else
            {
                if(colors[node] == colors[i])
                    return false;
            }
        }
        return true;
    }
};