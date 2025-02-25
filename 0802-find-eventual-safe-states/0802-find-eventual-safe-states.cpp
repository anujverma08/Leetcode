class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> graphRev(V);
        vector<int> indegree(V,0);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++){
            // i -> it
            // it -> i
            for (auto it : graph[i]){
                graphRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto neighbour : graphRev[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};