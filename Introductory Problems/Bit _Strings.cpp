#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000007
#define vll vector<long long>
#define dis(n) cout << n << endl
#define fo(i, N) for (int i = 0; i < N; ++i)
#define fos(i, b, N) for (int i = b; i < N; ++i)
#define forr(i, N) for (i = N; i >= 0; --i)

using namespace std;

/*
Total number of different binary strings of size n = 2 ^ n
- This can be achieved in linear time using the below approach or using 
  pow() function in c++
- We can also use BINARY EXPONENTIATION which can calculate a power in logarithmic
  time complexity.

Link for binary exponentiation :- https://cp-algorithms.com/algebra/binary-exp.html
*/

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long n;
  cin >> n;

  ll i, ans = 1;
  for (i = 0; i < n; ++i)
  {
    ans *= 2;
    ans = ans % O;
  }
  cout << ans << endl;
  return 0;
}