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

void dance() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void file() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
}

ll gcd(ll a, ll b) {
	return !b ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

template<typename t>
void printV(vector<t> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
}

bool isPrime(int n) {

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
int memo[201][21];
int price[22][22];
int shop(int money,int type)
{
    if(money<0)
        return noo;
    if(type==g)
        return m-money;
    if(memo[money][type]!=-1)
        return memo[money][type];
    int ret=noo;
    for(int i=1;i<=price[type][0];i++)
        ret=max(ret,shop(money-price[type][i],type+1));
    return memo[money][type]=ret;
}
int main()
{
	dance();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>g;
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<g;i++)
        {
            cin>>price[i][0];
            for(int j=1;j<=price[i][0];j++)
                cin>>price[i][j];
        }
        int res=shop(m,0);
        (res==noo)? cout<<"no solution\n":cout<<res<<"\n";

    }
	return 0;
}
