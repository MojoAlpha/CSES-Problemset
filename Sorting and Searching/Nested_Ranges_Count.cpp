#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define N 100005
#define MOD 1000000007
#define ar array
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

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool cmp(ar<int, 3> a, ar<int, 3> b)
{
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

void solution()
{
    ll n;
    cin >> n;
    vector<ar<int, 3>> a(n);
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r, i};
    }
    sort(a.begin(), a.end(), cmp);
    vi ans1(n), ans2(n);
    ordered_set<ar<int, 2>> os1, os2;

    for (int i = 0, j = n - 1; i < n; ++i, j--)
    {
        ans1[a[j][2]] = os1.order_of_key({a[j][1] + 1, -1});
        ans2[a[i][2]] = i - os2.order_of_key({a[i][1], -1});
        os1.insert({a[j][1], j});
        os2.insert({a[i][1], i});
    }

    for (int x : ans1)
        cout << x << " ";
    cout << endl;
    for (int x : ans2)
        cout << x << " ";
    cout << endl;
}

signed main()
{
    fastIO;
    solution();
    return 0;
}