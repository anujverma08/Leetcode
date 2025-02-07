class Solution {
public:
    void bfs(vector<vector<int>>& isConnected,vector<int>& visited,int root){
        int n = isConnected.size();
        queue<int> q;
        
        q.push(root);
        visited[root] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int neighbour : isConnected[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int province = 0;
        vector<vector<int>> adj(n+1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                bfs(adj,visited,i);
                province++;
            }
        }
        return province;
    }
};