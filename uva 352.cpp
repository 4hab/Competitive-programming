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
void dfs(int x,int y)
{
    arr[x][y]='0';
    for(int i=0;i<8;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(valid(a,b)&&arr[a][b]=='1')
            dfs(a,b);
    }
}
int main()
{
    dance();
    int tc=1;
    while(cin>>n)
    {
        m=n;
        int c=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(arr[i][j]=='1')dfs(i,j),c++;
        printf("Image number %d contains %d war eagles.\n",tc,c);
        tc++;
    }

}
/*
3 3
1 1 1
1 2 1
1 1 1
1 1 2
1 1 1
2 1 1


*/
