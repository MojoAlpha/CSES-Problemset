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
const long long oo = 10e17;
const double PI = 3.141592653589793238;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

ll n, m, a, b, c;
vector<vector<plll>> g;
vll dis;
vll p;

void dijkstra(long s)
{
    dis[s] = 0;
    priority_queue<plll, vector<plll>, greater<plll>> q;
    q.push({0, s});

    while (!q.empty())
    {
        ll v = q.top().second;
        ll dv = q.top().first;
        q.pop();
        if (dis[v] != dv)
            continue;

        for (auto edge : g[v])
        {
            ll to = edge.first;
            ll elen = edge.second;
            if (dis[v] + elen < dis[to])
            {
                dis[to] = dis[v] + elen;
                p[to] = v;
                q.push({dis[to], to});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    g.resize(n + 1);
    dis.resize(n + 1, oo);
    p.resize(n + 1, -1);

    for (long i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
    }

    dijkstra(1);

    for (long i = 1; i <= n; ++i)
        cout << dis[i] << " ";

    return 0;
}