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
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

vector<vll> gr;
vector<vector<pll>> from;
queue<pll> q;
pll A;
bool possible = false;
long n, m;
bool mons = false;
string ans;

void retrace(pll node)
{
    pll o = from[node.first][node.second];
    if (o == pll(-1, -1))
        return;
    if (o.first == node.first + 1)
        ans.push_back('U');
    if (o.first == node.first - 1)
        ans.push_back('D');
    if (o.second == node.second + 1)
        ans.push_back('L');
    if (o.second == node.second - 1)
        ans.push_back('R');
    retrace(o);
}

void check(pll o, pll d)
{
    long pl = gr[o.first][o.second];
    if (pl + 1 < gr[d.first][d.second])
    {
        gr[d.first][d.second] = pl + 1;
        q.push(d);
        from[d.first][d.second] = o;
    }
}

void bfs()
{
    while (!q.empty())
    {
        pll loc = q.front(), next;
        q.pop();
        next = loc;
        next.first++;
        check(loc, next);
        next = loc;
        next.first--;
        check(loc, next);
        next = loc;
        next.second++;
        check(loc, next);
        next = loc;
        next.second--;
        check(loc, next);
        if (mons && (loc.first == 0 || loc.second == 0 || loc.first == n - 1 || loc.second == m - 1))
        {
            cout << "YES\n";
            cout << gr[loc.first][loc.second] << endl;
            retrace(loc);
            possible = true;
            return;
        }
    }
}

int main()
{
    fast;
    cin >> n >> m;
    gr.resize(n);
    from.resize(n);
    fo(i, n)
    {
        gr[i].resize(m);
        from[i].resize(m);
    }

    fo(i, n)
    {
        string t;
        cin >> t;
        fo(j, m)
        {
            gr[i][j] = INT_MAX;
            if (t[j] == '#')
                gr[i][j] = 0;
            if (t[j] == 'M')
            {
                q.push(pll(i, j));
                gr[i][j] = 0;
            }
            if (t[j] == 'A')
            {
                A.first = i;
                A.second = j;
            }
        }
        bfs();
        mons = true;
        from[A.first][A.second] = pii(-1, -1);
        gr[A.first][A.second] = 0;
        q.push(A);
        bfs();
        if (possible)
        {
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }
        else
            cout << "NO\n";
    }
}