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

vector<vl> g;
vb vis;
vl team;
queue<long> q;
bool f = true;

void bfs(long n) {
    
    q.push(n);
    team[n] = 1;
    vis[n] = true;

    while(!q.empty()) {
        long p = q.front();
        q.pop();
        for(long i = 0; f && i < g[p].size(); ++i) {
            if(!vis[g[p][i]]) {
                if(team[p] == 1)
                    team[g[p][i]] = 2;
                else
                    team[g[p][i]] = 1;
                q.push(g[p][i]);
                vis[g[p][i]] = true;
           }
           else {
               if(team[g[p][i]] == team[p])
                    f = false;
           }
        }
    }
}

int main()
{   
    fast;
    long n, m, a, b;
    cin >> n >> m;

    g.resize(n + 1);
    vis.resize(n + 1, false);
    team.resize(n + 1, -1);

    fo(i, m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(long i = 1; f && i <= n; ++i) {
        if(!vis[i])
            bfs(i);
    }
    
    if(!f)
        cout << "IMPOSSIBLE";
    else
        fo(i, n) cout << team[i + 1] << " ";
    
    return 0;
}