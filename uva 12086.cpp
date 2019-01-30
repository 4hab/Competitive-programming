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


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> ii;

int dx[] = { 1,-1, 0, 0, 1, 1,-1, -1 };
int dy[] = { 0, 0, 1,-1, 1,-1, 1, -1 };

int kx[]= {2,2,-2,-2,1,1,-1,-1};
int ky[]= {1,-1,1,-1,2,-2,2,-2};

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
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

template<typename t>
void printV(vector<t> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

bool isPrime(int n)
{

    if (n == 2)
        return true;
    if (n < 2 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

/**
 *****code begins here*****
**/
ll MOD = 1000000007;
int lsone(int x)
{
    return x&(x*-1);
}
int n=200000;
ll ft[200001];
int rsq(int r)
{
    if(r==0)
        return 0;
    return ft[r]+rsq(r-lsone(r));
}
int rsq(int l,int r)
{
    if(l==1)
        return rsq(r);
    return rsq(r)-rsq(l-1);
}
void update(int p,int v)
{
    if(p>n)
        return;
    ft[p]+=v;
    update(p+lsone(p),v);
}

int main()
{
    int tc=1;
    //file();
    while(true)
    {
        memset(ft,0,sizeof(ft));
        int n;
        scanf("%d",&n);
        if(n==0)
            break;
        if(tc>1)
            printf("\n");
        vector<int> v(n+1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            update(i,v[i]);
        }
        printf("Case %d:\n",tc++);
        string q;
        while(true)
        {
            cin>>q;
            if(q=="END")break;
            int x,y;
            cin>>x>>y;
            if(q=="M")
            {
                printf("%d\n",rsq(x,y));
            }
            else
            {
                update(x,y-v[x]);
                v[x]=y;
            }
        }
    }
    return 0;

}
/*
5
10 10 50 50 90
5
10
20
50
70
90
*/
