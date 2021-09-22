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

/*
Simple greedy approach :-
Till the previous character is equal to the current character increase the 
current sum pointer; When both of these become unequal, capture this value and 
restore the current sum pointer to 0. The maximum value among the captured values
is your answer.
*/

int main()
{
    string s;
    cin >> s;
    long n = s.size();
    char curr = s[0];
    long i, reps = 0, maxim = 0;
    for (i = 0; i < n; ++i)
    {
        if (s[i] == curr)
            reps++;
        else
        {
            if (reps > maxim)
                maxim = reps;
            reps = 1;
            curr = s[i];
        }
    }
    if (reps > maxim)
        maxim = reps;
    cout << maxim << endl;
    return 0;
}