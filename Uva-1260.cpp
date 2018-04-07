    #include<bits/stdc++.h>
    #include<iostream>
    #include<iomanip>
    using namespace std;

    #define all(v)              v.begin(),v.end()
    #define allr(v)             v.rbegin(),v.rend()
    #define sz(v) (int)         v.size()
    #define loop(i,from,to)     for(int i=from;i<=to;i++)
    #define loopr(i,from,to)    for(int i=from;i>=to;i--)

    typedef long long ll;
    typedef unsigned long long ull;
    typedef vector<int> vi;
    typedef vector<pair<int,int> > vii;

    ll Gcd(ll a, ll b){return !b ? a : Gcd(b, a % b);}
    void dance()
        {
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
        }
    bool isprime(int n)
    {
        if(n<=2)return true;
        else if(n%2==0) return false;
        for(int i=3;i*i<=n;i+=2)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
int x;
bool ok(int num)
{
    return num<=x;
}
int main ()
{
     dance();
     int n,m;
     cin>>m;
     while(m--)
     {
         cin>>n;
         int c=0,total=0;
         vector<int> v(n);
         for(int i=0;i<n;i++)
         {
             cin>>v[i];
         }
         for(int i=1;i<n;i++)
         {
             x=v[i];
             c=count_if(v.begin(),v.begin()+i,ok);
             total+=c;
         }
         cout<<total<<endl;
     }
     return 0;
}
