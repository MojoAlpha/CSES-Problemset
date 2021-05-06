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

ll n, m, q;
vector<vll> g;

void floydWarshall()
{
    for (long k = 1; k <= n; ++k)
    {
        for (long i = 1; i <= n; ++i)
        {
            for (long j = 1; j <= n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
    }
}

int main()
{
    fast;
    cin >> n >> m >> q;
    g.resize(n + 1);
    for (long i = 0; i <= n; ++i)
        g[i].resize(n + 1, oo);
    for (long i = 0; i <= n; ++i)
        g[i][i] = 0;

    for (long i = 0; i < m; ++i)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        g[x][y] = min(k, g[x][y]);
        g[y][x] = min(k, g[y][x]);
    }
    floydWarshall();
    for (long i = 0; i < q; ++i)
    {
        long a, b;
        cin >> a >> b;
        if (g[a][b] == g[b][a] && g[a][b] == oo)
            cout << "-1\n";
        else
            cout << min(g[a][b], g[b][a]) << endl;
    }
    return 0;
}