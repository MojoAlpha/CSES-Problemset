#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define vl vector<long>
#define dis(n) cout << n << endl
#define fo(i, N) for (int i = 0; i < N; ++i)
#define fos(i, b, N) for (int i = b; i < N; ++i)
#define forr(i, N) for (i = N; i >= 0; --i)

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, t;
    cin >> n;
    multiset<long, less<int>> a;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        auto itr = a.upper_bound(t);
        if (itr == a.end())
            a.insert(t);
        else
        {
            a.insert(itr, t);
            a.erase(itr);
        }
    }

    cout << a.size();

    return 0;
}