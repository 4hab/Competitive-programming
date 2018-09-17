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


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> ii;

int dx[] = { 1,-1, 0, 0, 1, 1,-1, -1 };
int dy[] = { 0, 0, 1,-1, 1,-1, 1, -1 };

void dance()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void file()
{
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
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

int n,m,g;
bool dp[21][201];
int price[21][21];

int main()
{
    dance();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>g;
        memset(dp,false,sizeof(dp));
        for(int i=0; i<g; i++)
        {
            cin>>price[i][0];
            for(int j=1; j<=price[i][0]; j++)
                cin>>price[i][j];
        }
        for(int i=1; i<=price[0][0]; i++)
        {
            int pr=m-price[0][i];
            if(pr>=0)
                dp[0][pr]=true;

        }
        for(int i=1;i<g;i++)
        {
            for(int j=0;j<=200;j++)
            {
                for(int k=1;k<=price[i][0]&&dp[i-1][j];k++)
                {
                    int pr=j-price[i][k];
                    if(pr>=0)
                        dp[i][pr]=true;
                }
            }
        }
        int out=-1;
        for(int i=0;i<=200;i++)
            if(dp[g-1][i])
            {
                out=i;
                break;
            }
        if(out==-1)
            cout<<"no solution\n";
        else
            cout<<m-out<<"\n";
        }
    return 0;
}
