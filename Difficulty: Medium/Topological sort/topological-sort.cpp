//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans; // Stores the topological order
        vector<int> inDegree(V, 0); // Tracks in-degree of each node
        vector<vector<int>> graph(V); // Adjacency list for the graph
        
        // Step 1: Build the graph and compute in-degree for each node
        for(vector<int> &edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v); // Add directed edge u → v
            inDegree[v]++; // Increment in-degree of v
        }
        
        queue<int> q; // Queue for BFS traversal
        
        // Step 2: Find all nodes with in-degree = 0 (no dependencies)
        for(int i = 0; i < V; ++i) {
            if(inDegree[i] == 0) {
                q.push(i); // Add to queue for processing
            }
        }
        
        // Step 3: Process nodes in BFS manner
        while(!q.empty()) {
            int u = q.front(); 
            q.pop();
            ans.push_back(u); // Add to topological order
            
            // Reduce in-degree of neighbors
            for(int v : graph[u]) {
                inDegree[v]--;
                // If in-degree becomes 0, add to queue
                if(inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return ans; // Valid topological sort (guaranteed for DAG)
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int x = V;
        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(x, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends