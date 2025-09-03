class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize distance matrix
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;  
        }
        
        for (auto it : edges) {
            dis[it[0]][it[1]] = it[2];
            dis[it[1]][it[0]] = it[2];
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][k] != 1e9 && dis[k][j] != 1e9 &&
                        dis[i][k] + dis[k][j] < dis[i][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        
        int minCount = n;     
        int resultCity = -1;  
        
        for (int i = 0; i < n; i++) {
            int cnt = 0;       
            
            for (int j = 0; j < n; j++) {
                if (i != j && dis[i][j] <= distanceThreshold) {  
                    cnt++;
                }
            }
            
            if (cnt < minCount || (cnt == minCount && i > resultCity)) {
                minCount = cnt;
                resultCity = i;
            }
        }
        
        return resultCity;
    }
};
