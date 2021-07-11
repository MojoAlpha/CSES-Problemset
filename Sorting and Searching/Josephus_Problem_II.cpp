#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

/*
This problem is solved using set.
Normal set in STL is implemented using BSTs which are unbalanced, giving O(n) time complexity
Thus we use Red Black Trees which are auto balancing trees, giving O(log n) time complexity
*/

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
    fast;
    indexed_set s;
    long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        s.insert(i);

    int ind = k % n;
    while (n--)
    {
        auto y = s.find_by_order(ind);
        cout << *y << " ";
        s.erase(y);
        if (n)
            ind = (ind % n + k) % n;
    }
    return 0;
}