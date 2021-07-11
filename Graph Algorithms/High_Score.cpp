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

// negate the weights & then the problem turns
// into a standard bellmon ford shortest path algorithm

ll n, m;
vector<vll> edg(5005, vll(3));
vll dist(2505, oo);
vb vis1(2505, false), vis2(2505, false);
void dfs1(long s)
{
    if (vis1[s])
        return;
    vis1[s] = 1;
    for (auto i : ed)
}

int main()
{
    fast;
    cin >> n >> m;

    for (long i = 0; i < m; ++i)
    {
        cin >> edg[i][0] >> edg[i][1] >> edg[i][2];
        edg[i][2] *= -1;
    }

    dist[1] = 0;

    return 0;
}