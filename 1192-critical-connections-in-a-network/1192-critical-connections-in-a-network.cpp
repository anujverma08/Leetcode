#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int timer = 0; 
    
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, 
             vector<int>& low, vector<int>& tin, vector<vector<int>>& bridges) {
        
        vis[node] = 1;
        low[node] = tin[node] = timer++;  
        
        for(int neighbor : adj[node]) {
            if(neighbor == parent) continue;  
            
            if(vis[neighbor] == 0) {
                dfs(neighbor, node, adj, vis, low, tin, bridges);
                low[node] = min(low[node], low[neighbor]);
                
                if(low[neighbor] > tin[node]) {
                    bridges.push_back({node, neighbor}); 
                }
            } else {
                low[node] = min(low[node], tin[neighbor]); 
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n, 0);
        vector<int> low(n, 0);
        vector<int> tin(n, 0);
        vector<vector<int>> bridges;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, -1, adj, vis, low, tin, bridges);
            }
        }
        
        return bridges;
    }
};
