#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define vl vector<long>
#define dis(n) cout<<n<<endl
#define fo(i,N) for(int i=0; i<N; ++i)
#define fos(i,b,N) for(int i=b; i<N; ++i)
#define forr(i,N) for(i=N; i>=0; --i)
 
using namespace std;

int main()
{
    long n;
    cin >> n;
    queue<long> q;
    for(long i = 1; i <= n; ++i)
        q.push(i);
    
    while(!q.empty()) {
        long t = q.front();
        q.pop();
        q.push(t);
        t = q.front();
        cout << t << " ";
        q.pop();
    }
    
    return 0;
}