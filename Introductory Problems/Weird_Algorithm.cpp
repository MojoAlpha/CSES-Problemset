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

/*
This is a really basic question, just follow the steps its asking you in 
the problem itself. The series will always converge at 1. Why?

EXTRA PROOF :-
Let's take some cases to prove it :
Case 1 : n = 2^k, then number would converge surely
Case 2 : n != 2^k and is even, then after continuosly dividing it by 2
         we will surely obtain an odd number.
Case 3 : n != 2^k and is odd, on performing the operation ,
         - if(n % 4 == 1), the obtained number will be divisible by 4, thus eliminating 
         the odd set bit in the number
         - if(n % 4 == 3), the obtained number will be divisible by 2, the in the next two 
         steps will generate the above case and eliminate the odd set bit
*/

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    while (n != 1)
    {
        printf("%lld ", n);
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
    }
    printf("1");
    return 0;
}