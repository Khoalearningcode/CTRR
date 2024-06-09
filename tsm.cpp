#include "tsm.h"

int tsp(int mask, int pos, int start_index, int VISITED_ALL, int G[20][20], vector<vector<int>>& dp, vector<vector<int>>& parent) {
    if (mask == VISITED_ALL) {
        return G[pos][start_index] == 0 ? MAX : G[pos][start_index];
    }
    
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = MAX;
    for (int city = 0; city < dp.size(); city++) {
        if ((mask & (1 << city)) == 0 && G[pos][city] != 0) {
            int new_cost = G[pos][city] + tsp(mask | (1 << city), city, start_index, VISITED_ALL, G, dp, parent);
            if (new_cost < ans) {
                ans = new_cost;
                parent[pos][mask] = city;
            }
        }
    }
    return dp[pos][mask] = ans;
}

string Traveling(int G[20][20], int n, char start) {
    int start_index = start - 'A';
    int VISITED_ALL = (1 << n) - 1;

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    vector<vector<int>> parent(n, vector<int>(1 << n, -1));

    int min_cost = tsp(1 << start_index, start_index, start_index, VISITED_ALL, G, dp, parent);

    // Reconstruct the path
    int mask = 1 << start_index;
    int pos = start_index;
    vector<int> path;
    path.push_back(start_index);

    while (true) {
        pos = parent[pos][mask];
        if (pos == -1) break;
        path.push_back(pos);
        mask |= (1 << pos);
    }
    path.push_back(start_index);

    // Convert path to string
    stringstream ss;
    for (int i = 0; i < path.size(); ++i) {
        if (i != 0) ss << " ";
        ss << (char)(path[i] + 'A');
    }

    return ss.str();
}