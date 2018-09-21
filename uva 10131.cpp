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


int main()
{
    dance();
    vector<pair<int,pair<int,int> > > el;
    int n=0;
    int a,b;
    while(cin>>a>>b)
    {
        el.pb(mkpr(a,mkpr(b,n)));
        n++;
    }
    sort(all(el));
    int mx=0;
    int lis[1001];
    for(int i=0;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(lis[i]<lis[j]+1&&el[i].second.first<el[j].second.first)
                lis[i]=lis[j]+1;
        }
        mx=max(lis[i],mx);
    }
    cout<<mx<<endl;
    int v=mx;
    stack<int> st;
    int s=0;
    int ls=0;
    for(int i=n-1;i>=0;i--)
    {
        if(lis[i]==v&&el[i].second.first>ls)
        {
            ls=el[i].second.first;
            v--;
            st.push(el[i].second.second+1);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
/**uva
https://www.ideone.com/F08T1O
**/
