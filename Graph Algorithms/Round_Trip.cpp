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
vl par;

void dfs(long v, long p) {
    vis[v] = true;
    par[v] = p;
    for(long i = 0; i < g[v].size(); ++i) {
        if(!vis[g[v][i]])
            dfs(g[v][i], v);
        else if(g[v][i] != p) {
            vl cycle;
            long curr = v;
            cycle.push_back(curr);

            while(par[curr] != g[v][i]) {
                curr = par[curr];
                cycle.push_back(curr);
            }

            cycle.push_back(g[v][i]);
            cycle.push_back(v);

            cout << cycle.size() << endl;
            for(long i = 0; i < cycle.size(); ++i)
                cout << cycle[i] << " ";
            exit(0);
        }
    }
}

int main()
{   
    fast;
    long n, m, a, b;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, false);
    par.resize(n + 1, -1);
    vl res;

    fo(i, m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(long i = 1; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i, -1);
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}