#include <bits/stdc++.h>
#define ll long long
#define N 200005
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

template <class T>
struct SegT
{
    const T ID = INT_MAX;
    T minEl(T a, T b) { return min(a, b); }
    int n;
    vector<T> seg;
    void init(int _n)
    {
        n = _n;
        seg.assign(2 * n, ID);
    }
    void pull(int p) { seg[p] = minEl(seg[2 * p], seg[2 * p + 1]); }
    void update(int p, T val)
    {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2)
            pull(p);
    }
    T query(int l, int r)
    {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                ra = minEl(ra, seg[l++]);
            if (r & 1)
                rb = minEl(seg[--r], rb);
        }
        return minEl(ra, rb);
    }
};

SegT<ll> st;

int main()
{
    int n, q;
    cin >> n >> q;
    st.init(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        st.update(i, a);
    }
    while (q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
            st.update(a, b);
        else
            cout << st.query(a, b) << endl;
    }
    return 0;
}