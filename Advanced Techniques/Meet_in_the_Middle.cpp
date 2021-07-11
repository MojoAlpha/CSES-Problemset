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
#define fo(i, b, n) for (long i = b; i < n; ++i)
const double PI = 3.141592653589793238;
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

struct custom_hash // custom hash function for unordered map
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<ll, ll, custom_hash> mp; // storing generated combinations

signed main()
{
    fast;
    ll n, k, x, res = 0;
    cin >> n >> k;
    vll v1, v2;

    fo(i, 0, n / 2)
    {
        cin >> x;
        v1.push_back(x);
    }
    fo(i, n / 2, n)
    {
        cin >> x;
        v2.push_back(x);
    }
    ll n1 = n / 2, n2 = n - n1;

    for (ll i = 0; i < (1 << n1); ++i) //using bitset to generate all possible combinations
    {
        ll x = 0, y = 0, st = i;
        while (st > 0) // calculating sum value
        {
            if (st & 1)
                x += v1[y];
            y++;
            st >>= 1;
        }
        mp[x]++;
    }

    for (ll i = 0; i < (1 << n2); ++i)
    {
        ll x = 0, y = 0, st = i;
        while (st > 0)
        {
            if (st & 1)
                x += v2[y];
            y++;
            st >>= 1;
        }
        if (mp.count(k - x))
            res += mp[k - x];
    }
    cout << res;
    return 0;
}