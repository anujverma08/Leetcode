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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> map;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail= accounts[i][j];
                if(map.find(mail) == map.end()){
                    map[mail] = i;
                }else{
                    dsu.unionx(i, map[mail]);
                }
            }
        }
        vector<vector<string>> merged(n);
        for(auto it : map){
            string mail = it.first;
            int node = dsu.findUparent(it.second);
            merged[node].push_back(mail);
        }

        vector<vector<string>> res;
        for(int i = 0; i < n; i++){
            if(merged[i].size() == 0) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merged[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;




    }
};