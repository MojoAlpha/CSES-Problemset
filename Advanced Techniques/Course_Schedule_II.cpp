#include <bits/stdc++.h>

using namespace std;

#define N 100002
#define MOD 1000000007
#define MOD2 998244353
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout << fixed << setprecision(6);

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '"' << x << '"';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]" << endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

const double PI = 3.1415926535897932384626;
const ll oo = 9e18;
const double EPS = 1e-6;

int n, m, u, v;
vvi adj;
vi in;

void solution(int testno) {
    cin >> n >> m;
    adj.resize(n);
    in.assign(n, 0);
    fo(i,0,m) {
        cin >> u >> v;
        --u, --v;
        in[v]++;
        adj[u].pb(v);
    }

    priority_queue<int, vi, greater<int>> q;
    fo(i,0,n) if(!in[i]) q.push(i);
    while(!q.empty()) {
        multiset<int> ms;
        int sz = q.size();

        fo(i,0,sz) {
            int p = q.top();
            q.pop();
            cout << p + 1 << " ";
            for(int ed : adj[p]) {
                --in[ed];
                if(!in[ed]) ms.insert(ed);
            }
        }
        for(int i : ms) q.push(i);
    }
}

signed main()
{
    fastIO;
    int test = 1;
    clock_t begin, end;

    fo(i,1,test+1) {
        begin = clock();
        solution(i);
        end = clock();
        cerr << "[ Case :- " << i << " | Time Taken :- " << ((ld)end - (ld)begin) / CLOCKS_PER_SEC << " ]" << endl;
    }
    return 0;
}