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
    ll n, m, ticket, buyer;
    cin >> n >> m;
    multiset<ll, greater<int>> tickets;
    for (int i = 0; i < n; ++i)
    {
        cin >> ticket;
        tickets.insert(ticket);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> buyer;
        auto itr = tickets.lower_bound(buyer);
        if (itr == tickets.end())
            cout << "-1\n";
        else
        {
            cout << *itr << endl;
            tickets.erase(itr);
        }
    }
    return 0;
}