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

vector<string> g;
vector<vb> vis;

void dfs(long a, long n, long b, long m) {
    vis[a][b] = true;
    if(a + 1 < n && g[a + 1][b] == '.' && !vis[a + 1][b])
        dfs(a + 1, n, b, m);
    if(b + 1 < m && g[a][b + 1] == '.' && !vis[a][b + 1])
        dfs(a, n, b + 1, m);
    if(a - 1 >= 0 && g[a - 1][b] == '.' && !vis[a - 1][b])
        dfs(a - 1, n, b, m);
    if(b - 1 >= 0 && g[a][b - 1] == '.' && !vis[a][b - 1])
        dfs(a, n, b - 1, m);
}

int main()
{   
    fast;
    long n, m, res = 0;
    cin >> n >> m;
    g.resize(n);
    fo(i, n)
        cin >> g[i];
    vis.resize(n);
    fo(i, n) vis[i].resize(m, false);

    for(long i = 0; i < n; ++i) {
        for(long j = 0; j < m; ++j) {
            if(g[i][j] == '.' && !vis[i][j]) {
                res++;
                dfs(i, n, j, m);
            }
        }
    }

    cout << res;
    return 0;
}