#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define dis(n) cout << n << endl
#define fo(i, N) for (int i = 0; i < N; ++i)
#define fos(i, b, N) for (int i = b; i < N; ++i)
#define forr(i, N) for (i = N; i >= 0; --i)

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long t;
  cin >> t;

  for (int i = 1; i <= t; ++i)
  {
    if (i == 1)
      cout << "0\n";
    else if (i == 2)
      cout << "6\n";
    else
    {
      ll n = i * i;
      cout << (n * (n - 1)) / 2 - 4 * (i - 1) * (i - 2) << endl;
    }
  }
  return 0;
}