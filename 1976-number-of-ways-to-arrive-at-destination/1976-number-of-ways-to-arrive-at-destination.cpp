class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int time = it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n, 1e18);  
        vector<int> ways(n,0);
        int mod = (int)(1e9 + 7);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto temp = pq.top();
            long long dis = temp.first;  
            int node = temp.second;
            pq.pop();

            if (dis > dist[node]) continue;

            for(auto it : adj[node]){
                int newNode = it.first;
                int edgeWeight = it.second;

                if(dis + edgeWeight < dist[newNode]){
                    dist[newNode] = dis + edgeWeight;
                    pq.push({dist[newNode], newNode});
                    ways[newNode] = ways[node];
                } else if(dis + edgeWeight == dist[newNode]){
                    ways[newNode] = (ways[newNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};
