class Solution {
public:
    /** 
        recursion, dfs. construct a bidirection graph using dislikes and check if the graph is bipartite
        time O(E + V)
        space O(E + V)
    */
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph = buildGraph(n, dislikes);
        vector<int> colors(n + 1, 0);   // k: index of node, v: 0 = unvisited, 1 = color A, -1 = color B
        for(int i = 1; i < graph.size(); ++i)
        {
            if(colors[i] == 0)  // only check unvisited node
            {
                if(!dfs(graph, colors, i, 1))
                    return false;
            }
        }
        return true;
    }

private:
    //// build the bidirection graph
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> graph(n + 1, vector<int>());   // index range: [1, n]
        for(auto& edge : dislikes)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    //// return false if there are two adjacent nodes have the same color in graph[i]
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int i, int color)
    {
        colors[i] = color;
        for(auto& node : graph[i])
        {
            if(colors[node] == 0)   // unvisited node, set and check color
            {
                if(!dfs(graph, colors, node, -color))
                    return false;
            }
            else    // visited node, check color
            {
                if(colors[node] == color)
                    return false;
            }
        }
        return true;
    }
};