#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, val, sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.precision(12);

typedef long long ll;
typedef pair<long, long> pll;
typedef pair<ll, ll> plll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vl> vvl;
typedef vector<vll> vvll;

const double PI = 3.141592653589793238;
const ll oo = 1e18;

void solution()
{
    ll n, x;
    cin >> n >> x;
    vll a(n);
    fo(i, 0, n) cin >> a[i];
    priority_queue<ll> pq;

    fo(i, 0, n)
    {
        if (pq.empty())
        {
            pq.push(0);
            continue;
        }
        if (pq.top() + a[i] <= x)
        {
            ll val = pq.top();
            pq.pop();
            pq.push(val + a[i]);
        }
        else
            pq.push(a[i]);
    }
    cout << pq.size();
}

signed main()
{
    fastIO;
    solution();
    return 0;
}