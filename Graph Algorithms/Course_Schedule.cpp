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

long n, m, a, b;
vector<vl> adj;
bool f = true;
vb vis;
vl order, par;

void dfs(long n)
{
    vis[n] = true;
    for (long i = 0; f && i < adj[n].size(); ++i)
    {
        if (!vis[adj[n][i]])
        {
            par[adj[n][i]] = n;
            dfs(adj[n][i]);
        }
        else if (par[adj[n][i]] == n)
        {
            f = false;
            return;
        }
    }
    order.push_back(n);
}

void topological_sort()
{
    order.clear();
    for (long i = 1; f && i <= n; ++i)
    {
        if (!vis[i])
            dfs(i);
    }

    if (!f)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(order.begin(), order.end());
    for (long i = 0; i < order.size(); ++i)
        cout << order[i] << " ";
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, false);
    par.resize(n + 1, -1);

    for (long i = 0; i < m; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    topological_sort();
    return 0;
}