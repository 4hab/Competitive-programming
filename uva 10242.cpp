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
int main()
{
    dance();
    //file();
    cout<<fixed<<setprecision(3);
    double x,y;
    while(cin>>x>>y)
    {
        pair<double,double> p1,p2,p3;
        map<pair<double,double>,int > mp;
        mp[{x,y}]++;
        cin>>x>>y;
        mp[{x,y}]++;
        cin>>x>>y;
        mp[{x,y}]++;
        cin>>x>>y;
        mp[{x,y}]++;
        int pos=1;
        for(auto p:mp)
        {
            if(p.second==2)
            {
                p2=p.first;
            }
            else if(pos==1)
            {
                p1=p.first;
                pos=2;
            }
            else
                p3=p.first;
        }
        cout<<p1.ff+p3.ff-p2.ff<<' '<<p3.ss+p1.ss-p2.ss<<endl;

    }
}
/**
0.000 0.000 0.000 1.000 0.000 1.000 1.000 1.000
1.000 0.000 3.500 3.500 3.500 3.500 0.000 1.000
1.866 0.000 3.127 3.543 3.127 3.543 1.412 3.145
**/
