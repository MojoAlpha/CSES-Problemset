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
vl par;
queue<long> q;

void bfs(long n) {
    q.push(n);
    par[n] = -1;
    vis[n] = true;

    while(!q.empty()) {
        long p = q.front();
        q.pop();
        for(long i = 0; i < g[p].size(); ++i) {
            if(!vis[g[p][i]]) {
                par[g[p][i]] = p;
                q.push(g[p][i]);
                vis[g[p][i]] = true;
           }
        }
    }
}

void printRoute(long n) {
    vl path;
    long p = n;
    while(p != -1) {
        path.push_back(p);
        p = par[p];
    }

    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    fo(i, path.size()) cout << path[i] << " ";
}

int main()
{   
    fast;
    long n, m, a, b;
    cin >> n >> m;

    g.resize(n + 1);
    vis.resize(n + 1, false);
    par.resize(n + 1, -1);

    fo(i, m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    bfs(1);
    
    if(par[n] == -1)
        cout << "IMPOSSIBLE";
    else
        printRoute(n);
    return 0;
}