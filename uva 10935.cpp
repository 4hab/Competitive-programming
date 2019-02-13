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
typedef vector<vector<int> > vvi;

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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
bool solve(pair<int,string>&a,pair<int,string> &b)
{
    if(a.first>b.first)
        return 1;
    else if(a.ff==b.ff)
    {
        return a.ss<b.ss;
    }
    return 0;
}



/**
 *****code begins here*****
**/
ll MOD = 1000000007;
vvi adj;
int rec[4001];
bool used[4001];
int mn=oo;
bool found=false;
void dfs(int i,int p=-1,int pp=-1)
{
    used[i]=true;
    for(auto ch:adj[i])
    {
        if(ch==pp)
        {
            mn=min(mn,rec[i]+rec[p]+rec[pp]);
            found=true;
        }
        else if(!used[ch])
            dfs(ch,i,p);
    }
}
int main()
{
    dance();
    //file();
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        queue<int> q;
        for(int i=1; i<=n; i++)q.push(i);
        printf("Discarded cards:");
        bool com=false;
        while(q.size()>1)
        {
            if(com)printf(",");
            printf(" %d",q.front());
            q.pop();
            int x=q.front();
            q.pop();
            q.push(x);
            com=true;
        }
        printf("\nRemaining card: ");
        printf("%d\n",q.front());
    }
}

