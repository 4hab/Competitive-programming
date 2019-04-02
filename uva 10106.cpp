#include<bits/stdc++.h>


using namespace std;

#define all(v)              v.begin(),v.end()
#define allr(v)             v.rbegin(),v.rend()
#define sz(v)               (int)sizeof(v)
#define pb(x)               push_back(x)
#define mkpr(x,y)           make_pair(x,y)
#define oo                  INT_MAX
#define noo                 INT_MIN
#define forn(i, n)          for(ll i=0;i<n;i++)
#define fore(i,b,e)         for(ll i=b;i<=e;i++)
#define ford(i,n)           for(ll i=n-1;i>=0;i--)
#define EPS                 1e-9
#define ff                  first
#define ss                  second
#define pi                  acos(-1)


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> ii;
typedef vector<vector<int> > vvi;

int dx[] = { 1,-1, 0, 0,1, 1,-1, -1 };
int dy[] = { 0, 0, 1,-1,1,-1, 1, -1 };

void dance()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void file()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}

/**
 *****code begins here*****
**/
int v[501],res[501];
int main()
{
    dance();
    //file();
    int t;
    string a,b;
    while(cin>>a>>b)
    {
        reverse(all(a));
        reverse(all(b));
        memset(v,0,sizeof(v));
        memset(res,0,sizeof(res));
        for(int i=0; i<a.size(); i++)
        {
            int p=i,carr=0;
            int x=a[i]-'0';
            for(int j=0; j<b.size(); j++,p++)
            {
                int y=b[j]-'0';
                int val=x*y+carr;
                v[p]=val%10;
                carr=val/10;
            }
            while(carr)
            {
                v[p++]=carr%10;
                carr/=10;
            }
            for(int i=0; i<=500; i++)
            {
                int val=res[i]+v[i]+carr;
                res[i]=val%10;
                carr=val/10;
                v[i]=0;
            }
        }
        bool nz=false;
        for(int i=500; i>=0; i--)
        {
            if(res[i]>0)
                nz=true;
            if(nz)
                cout<<res[i];
        }
        if(!nz)
            cout<<0;
        cout<<endl;
    }

}
