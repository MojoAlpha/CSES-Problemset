#include<bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n, m, u, v;
vector<vector<int>> adj, adjr;
vector<bool> vis;
vector<int> order, comp;

void dfs1(int ver) {
    vis[ver] = true;
    for(auto &ed : adj[ver])
        if(!vis[ed]) dfs1(ed);
    order.push_back(ver);
}

void dfs2(int ver) {
    vis[ver] = true;
    comp.push_back(ver);
    for(auto &ed : adjr[ver])
        if(!vis[ed]) dfs2(ed);
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    adjr.resize(n);
    vis.assign(n, false);

    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }
    for(int i = 0; i < n; ++i)
        if(!vis[i]) dfs1(i);

    vis.assign(n, false);
    reverse(order.begin(), order.end());

    dfs2(order[0]);
    if(comp.size() == n) cout << "YES";
    else {
        cout << "NO\n";
        bool f = 1;
        int u = -1, v = -1;
        for(int i = 0; i < n && f; ++i) {
            if(vis[i]) u = i;
            else v = i;
            for(int &ed : adj[i]) {
                if(vis[i] && !vis[ed]) {
                    cout << ed + 1 << " " << i + 1;
                    f = 0;
                    break;
                }
                if(!vis[i] && vis[ed]) {
                    cout << i + 1 << " " << ed + 1;
                    f = 0;
                    break;
                }
            }
        }

        if(f)
            cout << u + 1 << " " << v + 1;
    }

    return 0;
}