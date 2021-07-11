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

int trie[1000005][26];
int stop[1000005];
int dp[5005];
int ct = 0;

void insert(string s)
{
    int node = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (!trie[node][s[i] - 'a'])
            trie[node][s[i] - 'a'] = ++ct;
        node = trie[node][s[i] - 'a'];
    }
    stop[node] = 1;
}
string s;

int search(int x)
{
    int node = 0, ans = 0;
    for (int i = x; i < s.size(); ++i)
    {
        if (!trie[node][s[i] - 'a'])
            return ans;
        node = trie[node][s[i] - 'a'];
        if (stop[node])
        {
            ans = (ans + dp[i + 1]) % O;
        }
    }
    return ans;
}

void solve()
{
    cin >> s;
    long k;
    cin >> k;
    while (k--)
    {
        string x;
        cin >> x;
        insert(x);
    }
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; --i)
        dp[i] = search(i);
    cout << dp[0];
}

int main()
{
    fast;
    solve();
    return 0;
}