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
#define fos(i, b, n) for (long i = b; i < n; ++i)
const double PI = 3.141592653589793238;
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

vector<vl> adj(N);
vl path;
long n, m;
vi vis(N, 0);
bool found = false;

void printPath()
{
    long i = path.size() - 2, cnt = 1;
    while (i >= 0 && path[i] != path.back())
    {
        cnt++;
        --i;
    }
    cout << cnt + 1 << endl;
    while (i < path.size())
        cout << path[i++] << " ";
}

void dfs(long s)
{
    vis[s] = 1;
    path.push_back(s);
    for (auto i : adj[s])
    {
        if (vis[i] == 0)
            dfs(i);
        else if (vis[i] == 1)
        {
            found = true;
            path.push_back(i);
            printPath();
            return;
        }
    }
    vis[s] = 2;
}

void solve()
{
    long a, b;
    cin >> n >> m;
    fos(i, 0, m)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    fos(i, 1, n + 1)
    {
        if (vis[i] == 0)
        {
            dfs(i);
            if (found)
                return;
            path.clear();
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    fast;
    solve();
    return 0;
}