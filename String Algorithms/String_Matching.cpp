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

int rabin_karp_count(string &s, string &p)
{
    const int f = 31; // mutiplicative constant
    int ns = s.size(), np = p.size(), res = 0;

    vll p_pow(max(ns, np));
    p_pow[0] = 1;
    for (long i = 1; i < p_pow.size(); ++i) // generating powers of f
        p_pow[i] = (p_pow[i - 1] * f) % O;

    vll h(ns + 1, 0);
    for (long i = 0; i < ns; ++i) // generating hash of sample string
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % O;
    ll hp = 0;
    for (long i = 0; i < np; ++i) // calculating hash value of pattern
        hp = (hp + (p[i] - 'a' + 1) * p_pow[i]) % O;

    for (long i = 0; i + np - 1 < ns; ++i) // counting substrings with same hash value
    {
        ll tmp = (h[i + np] + O - h[i]) % O;
        if (tmp == hp * p_pow[i] % O)
            res++;
    }
    return res;
}

void solve()
{
    string s, p;
    cin >> s >> p;
    cout << rabin_karp_count(s, p);
}

int main()
{
    fast;
    solve();
    return 0;
}