#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

struct LCA {
    int N;
    int logn;
    vector<int> depth;
    vector<int> dist;
    vector<vector<int>> ancestor;
    vector<vector<pair<int, int>>> edges;

    LCA(int N) : N(N) {
        logn = (int)log2(N) + 2;
        depth = vector(N, 0);
        dist = vector(N, 0);
        ancestor = vector(logn, vector(N, -1));
        edges = vector(N, vector<pair<int, int>>());
    }

    void add_edge(int u, int v) {
        edges[u].push_back({v, 1});
        edges[v].push_back({u, 1});
    }

    void add_edge(int u, int v, int w) {
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    void build(int root) {
        vector<int> sta;
        sta.push_back(root);
        while (sta.size()) {
            auto cur = sta.back();
            sta.pop_back();
            for (auto [nx, w] : edges[cur]) {
                if (ancestor[0][nx] != cur && ancestor[0][cur] != nx) {
                    ancestor[0][nx] = cur;
                    depth[nx] = depth[cur] + 1;
                    dist[nx] = dist[cur] + w;
                    sta.push_back(nx);
                }
            }
        }

        for (int k = 1; k < logn; ++k) {
            for (int i = 0; i < N; ++i) {
                if (ancestor[k - 1][i] == -1) {
                    ancestor[k][i] = -1;
                } else {
                    ancestor[k][i] = ancestor[k - 1][ancestor[k - 1][i]];
                }
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] > depth[v]) {
            swap(u, v);
        }

        for (int k = logn - 1; k > -1; --k) {
            if (((depth[v] - depth[u]) >> k) & 1) {
                v = ancestor[k][v];
            }
        }

        if (u == v) {
            return u;
        }

        for (int k = logn - 1; k > -1; --k) {
            if (ancestor[k][u] != ancestor[k][v]) {
                u = ancestor[k][u];
                v = ancestor[k][v];
            }
        }

        return ancestor[0][u];
    }

    int get_dist(int u, int v) {
        return dist[v] + dist[u] - 2 * dist[lca(u, v)];
    }
};
