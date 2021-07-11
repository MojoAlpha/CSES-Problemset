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
vi vis;
stack<long> st;

void dfs(long n)
{
    vis[n] = 1;
    for (auto edge : adj[n])
    {
        if (vis[edge] == 0)
            dfs(edge);
        else if (vis[edge] == 1)
        {
            f = false;
            return;
        }
    }
    st.push(n);
    vis[n] = 2;
}

void topological_sort()
{
    for (long i = 1; f && i <= n; ++i)
    {
        if (vis[i] == 0)
            dfs(i);
    }

    if (!f)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    fast;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, 0);

    for (long i = 0; i < m; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    topological_sort();
    return 0;
}