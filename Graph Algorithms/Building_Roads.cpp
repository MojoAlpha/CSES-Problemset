#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000005
#define O 1000000007
#define vi vector<int>
#define vl vector<long>
#define vb vector<bool>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long, long>
#define fo(i, N) for (long i = 0; i < N; ++i)
#define fos(i, b, N) for (long i = b; i < N; ++i)
#define forr(i, N) for (long i = N; i >= 0; --i)
const double PI = 3.141592653589793238;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

vector<vl> g;
vb vis;

void dfs(long v) {
    vis[v] = true;
    for(long i = 0; i < g[v].size(); ++i) {
        if(!vis[g[v][i]])
            dfs(g[v][i]);
    }
}

int main()
{   
    fast;
    long n, m, a, b;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, false);
    vl res;

    fo(i, m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(long i = 1; i <= n; ++i) {
        if(!vis[i]) {
            res.push_back(i);
            dfs(i);
        }
    }

    cout << res.size() - 1 << endl;
    fo(i, res.size() - 1)
        cout << res[i] << " " << res[i + 1] << endl;

    return 0;
}