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
#define plll pair<long long, long long>
#define fo(i, N) for (long i = 0; i < N; ++i)
#define fos(i, b, N) for (long i = b; i < N; ++i)
#define forr(i, N) for (long i = N; i >= 0; --i)
const double PI = 3.141592653589793238;
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

long n, m;
vector<vector<plll>> adj;
vi vis, cycle;
bool f = false;

void negCycle(long s, long wt)
{
    vis[s] = 1;
    cycle.push_back(s);
    for (auto edge : adj[s])
    {
        if (vis[edge.first] == 0)
            negCycle(edge.first, edge.second + wt);
        else if (vis[edge.first] == 1 && wt + edge.second < 0)
        {
            f = true;
            cout << "YES\n"
                 << edge.first << " ";
            while (cycle.back() != edge.first)
            {
                cout << cycle.back() << " ";
                cycle.pop_back();
            }
            cout << cycle.back();
            return;
        }
        if (f)
            break;
    }
    vis[s] = 2;
}

void solve()
{
    ll a, b, c;
    cin >> n >> m;
    adj.resize(n + 1);
    for (long i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vis.resize(n + 1, 0);
    for (int i = 1; !f && i <= n; ++i)
    {
        cycle.clear();
        if (vis[i] == 0)
            negCycle(i, 0);
    }

    if (!f)
        cout << "NO";
}

int main()
{
    fast;
    solve();
    return 0;
}