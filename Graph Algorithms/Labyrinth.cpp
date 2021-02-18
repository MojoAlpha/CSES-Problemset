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

vector<string> lab;
vector<vb> vis;
vector<string> dir;
long n, m;
queue<pll> q;

void bfs(long x, long y) {
    
    q.push(make_pair(x, y));
    vis[x][y] = true;

    while(!q.empty()) {
        pll p = q.front();

        q.pop();
        if(p.first + 1 < n && lab[p.first + 1][p.second] != '#' && !vis[p.first + 1][p.second]) {
            q.push(make_pair(p.first + 1, p.second));
            vis[p.first + 1][p.second] = true;
            dir[p.first + 1][p.second] = 'D';
        }
        if(p.first - 1 >= 0 && lab[p.first - 1][p.second] != '#' && !vis[p.first - 1][p.second]) {
            q.push(make_pair(p.first - 1, p.second));
            vis[p.first - 1][p.second] = true;
            dir[p.first - 1][p.second] = 'U';
        }
        if(p.second + 1 < m && lab[p.first][p.second + 1] != '#' && !vis[p.first][p.second + 1]) {
            q.push(make_pair(p.first, p.second + 1));
            vis[p.first][p.second + 1] = true;
            dir[p.first][p.second + 1] = 'R';
        }
        if(p.second - 1 >= 0 && lab[p.first][p.second - 1] != '#' && !vis[p.first][p.second - 1]) {
            q.push(make_pair(p.first, p.second - 1));
            vis[p.first][p.second - 1] = true;
            dir[p.first][p.second - 1] = 'L';
        }
    }
}

int main()
{   
    fast;
    cin >> n >> m;
    lab.resize(n);
    vis.resize(n);
    dir.resize(n);
    fo(i, n) cin >> lab[i];

    fo(i, n) {
        vis[i].resize(m, false);
        dir[i].resize(m, '\0');
    }

    long x1, x2, y1, y2;
    for(long i = 0; i < n; ++i) {
        for(long j = 0; j < m; ++j)
            if(lab[i][j] == 'A')  {
                x1 = i;
                y1 = j;
            }
            else if(lab[i][j] == 'B') {
                x2 = i;
                y2 = j;
            }
    }

    bfs(x1, y1);

    string res = "";
    if(dir[x2][y2] == '\0')
        cout << "NO";
    else
    {
        cout << "YES\n";
        while(dir[x2][y2] != '\0') {
            res += dir[x2][y2];
            if(dir[x2][y2] == 'U')
                x2++;
            else if(dir[x2][y2] == 'D')
                x2--;
            else if(dir[x2][y2] == 'L')
                y2++;
            else
                y2--;
        }
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        cout << res;
    }
    return 0;
}