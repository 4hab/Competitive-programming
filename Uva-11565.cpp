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
int a,b,c;
bool check(int x,int y,int z)
{
    if(x+y+z==a&&x*y*z==b&&(x*x+y*y+z*z)==c)
        return true;
    return false;
}
int main ()
{
     dance();
     int m;
     cin>>m;
     while(m--)
     {

         cin>>a>>b>>c;
         for(int i=-100;i<=100;i++)
         {
             for(int j=i+1;j<=100;j++)
             {
                 for(int k=j+1;k<=100;k++)
                 {
                     if(check(i,j,k))
                     {
                         cout<<i<<' '<<j<<' '<<k<<endl;
                         goto k1;
                     }
                 }
             }
         }
         cout<<"No solution."<<endl;
         k1:
             ;
     }
     return 0;
}
