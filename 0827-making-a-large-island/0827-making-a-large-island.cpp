class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);  
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        parent[node] = findParent(parent[node]);
        return parent[node];  
    }

    void unionSize(int u, int v) {
        int pu = findParent(u); 
        int pv = findParent(v);

        if (pu == pv) return; 

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];   
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    bool isValid(int row, int col, int n, int m){
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n * m);
        vector<pair<int, int>> directions =  {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if (grid[row][col] == 0) continue;
                for(auto dir : directions){
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;
                    if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1){
                        int node = row * m + col;
                        int newNode = nrow * m + ncol;
                        dsu.unionSize(node, newNode);
                    }
                }
            }
        }
        int mx = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 1) continue;
                set<int> components;
                for(auto dir : directions){
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;
                    if(isValid(nrow, ncol, n , m)){
                        if(grid[nrow][ncol] == 1){
                            components.insert(dsu.findParent(nrow * m + ncol));
                        }
                    }
                }
                int sizeTotal = 0;
                for(auto it : components){
                    sizeTotal += dsu.size[it];
                }
                mx = max(sizeTotal + 1, mx);
            }
        }

        for(int cell = 0; cell < n * m; cell++){
            mx= max(mx, dsu.size[dsu.findParent(cell)]);
        }
        return mx;

    }   
};