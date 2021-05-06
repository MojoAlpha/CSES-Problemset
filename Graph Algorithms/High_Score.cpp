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

struct edge
{
    ll a, b, points;
};

vector<edge> e;
ll n, m;
vll dist;

void bford()
{
    dist.resize(n + 1, oo);
    dist[1] = 0;
    for (;;)
    {
        bool any_changes = false;

        for (long j = 0; j < m; ++j)
        {
            if (dist[e[j].a] < oo)
            {
                if (dist[e[j].b] > dist[e[j].a] + e[j].points)
                {
                    dist[e[j].b] = dist[e[j].a] + e[j].points;
                    any_changes = true;
                }
            }
        }
        if (!any_changes)
            break;
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (long i = 0; i < m; ++i)
    {
        edge tmp;
        cin >> tmp.a >> tmp.b >> tmp.points;
        e.push_back(tmp);
    }

    bford();

    if (dist[n] == oo)
        cout << "-1";
    else
        cout << dist[n];

    return 0;
}