#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define dis(n) cout<<n<<endl
#define fo(i,N) for(int i=0; i<N; ++i)
#define fos(i,b,N) for(int i=b; i<N; ++i)
#define forr(i,N) for(i=N; i>=0; --i)

using namespace std;
int main()
{
    long n;
    cin>>n;
    ll total = (n * (n + 1)) / 2;
    if(total % 2 != 0)
      cout<<"NO\n";
    else
    {
        ll target = total / 2, sum1=0, sum2=0;
        vll part1, part2;
        while(n != 0)
        {
          if(n <= target)
          {
            target -= n;
            sum1 += n;
            part1.push_back(n);
            n--;
          }
          else{
            sum2 += n;
            part2.push_back(n);
            n--;
          }
        }
        if(target != 0)
        cout<<"NO\n";
        else if(sum1 == sum2)
        {
          cout<<"YES\n";
          cout<<part1.size()<<endl;
          for(int i = 0; i< part1.size(); ++i)
            cout<<part1[i]<<" ";
          cout<<endl;
          cout<<part2.size()<<endl;
          for(int i = 0; i< part2.size(); ++i)
            cout<<part2[i]<<" ";
          cout<<endl;
        } 
        else
        cout<<"NO\n";
    }
    
    return 0;
}