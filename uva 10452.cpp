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

int kx[]= {1,1,-1,-1,2,2,-2,-2,};
int ky[]= {-2,2,-2,2,-1,1,-1,1};


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
long double costs,w;
bool comp(pair<double,double>&a,pair<double,double> &b)
{
    long double A=a.ff*w+(costs-a.ff)*w*a.ss,B=b.ff*w+(costs-b.ff)*w*b.ss;
    if(A<B)
        return 1;
    else if(A==B)
    {
        return a.ff<b.ff;
    }
    return 0;
}


ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}

/**
 *****code begins here*****
**/

ll mod = 1e9+7;
int n,m;
char arr[25][25];
bool valid(int x,int y)
{
    return (x>=0&&x<n&&y>=0&&y<m);
}
string sav="IEHOVA#";

vector<string> steps;
void dfs(int x,int y,int sn=0)
{
    if(arr[x][y]=='#')
        return;
    if(valid(x-1,y)&&arr[x-1][y]==sav[sn])
    {
        steps.push_back("forth");
        dfs(x-1,y,sn+1);
    }
    if(valid(x,y+1)&&arr[x][y+1]==sav[sn])
    {
        steps.pb("right");
        dfs(x,y+1,sn+1);
    }
    if(valid(x,y-1)&&arr[x][y-1]==sav[sn])
    {
        steps.pb("left");
        dfs(x,y-1,sn+1);
    }
}
int main()
{
    dance();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int x,y;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='@')
            {
                x=i;
                y=j;
            }
        }
        dfs(x,y);
        cout<<steps[0];
        for(int i=1;i<steps.size();i++)
            cout<<' '<<steps[i];
        cout<<endl;
        steps.clear();
    }

}

