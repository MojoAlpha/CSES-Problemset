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

void TOH(int a, int b, int c, int n)
{
    if (n == 1)
    {
        cout << a << " " << c << endl;
        return;
    }

    TOH(a, c, b, n - 1);
    cout << a << " " << c << endl;
    TOH(b, a, c, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    TOH(1, 2, 3, n);
    return 0;
}