#define sz(s) (int)s.size()

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        int cost[n + 1];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        for (int i = 0; i <= n; i++)
            cost[i] = 1e9;

        queue<pair<int, pair<int, int>>> qe;
        qe.push({src, {0, 0}});
        while (!qe.empty()) {
            int pa = qe.front().first, price = qe.front().second.first,
                kk = qe.front().second.second;
            qe.pop();
            for (auto ch : adj[pa]) {
                if (cost[ch.first] > price + ch.second && kk <= k) {
                    qe.push({ch.first, {price + ch.second, kk + 1}});
                    cost[ch.first] = price + ch.second;
                }
            }
        }
        if (cost[dst] == 1e9)
            return -1;
        else
            return cost[dst];
    }
};
