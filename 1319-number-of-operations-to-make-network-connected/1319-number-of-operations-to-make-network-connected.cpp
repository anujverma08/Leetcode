class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0); 
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int x) {
        if (parent[x] != x)
            parent[x] = findUparent(parent[x]); 
        return parent[x];
    }

    void unionx(int x, int y) {
        int px = findUparent(x);
        int py = findUparent(y);
        
        if (px == py)
            return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int extra = 0;
        for(auto it : connections){
            int x = it[0];
            int y = it[1];
            if(dsu.findUparent(x) == dsu.findUparent(y)){
                extra++;
            }else{
                dsu.unionx(x, y);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i == dsu.parent[i]) ans++;
        }

        ans -= 1;
        if(ans <= extra){
            return ans;
        }else return -1;
    }
};