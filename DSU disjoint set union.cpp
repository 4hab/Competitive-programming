#include<bits/stdc++.h>


using namespace std;

#define all(v)              v.begin(),v.end()
#define allr(v)             v.rbegin(),v.rend()
#define sz(v)               (int)sizeof(v)
#define pb(x)               push_back(x)
#define mkpr(x,y)           make_pair(x,y)
#define oo                  INT_MAX
#define noo                 INT_MIN
#define rep(i,n)            for(int i=0;i<n;i++)
#define EPS                 1e-9
#define ff                  first
#define ss                  second
#define pi                  acos(-1)
#define PI                  3.14159265

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
int parent[100];
int raank[100];
void initParent(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        raank[i]=1;
    }
}
int findParent(int x)
{
    if(parent[x]==x)
        return x;
    return parent[x]=findParent(parent[x]);
}
void uni(int a,int b)
{
    int pa=findParent(a);
    int pb=findParent(b);
    if(raank[pa]>raank[pb])
    {
        parent[pb]=pa;
        raank[pa]+=raank[pb];
    }
    else
    {
        parent[pa]=pb;
        raank[pb]+=raank[pb];
    }

}
bool sameSet(int a,int b)
{
    return findParent(a)==findParent(b);
}
int main()
{
    initParent(100);
    char c;
    int a,b;
    while(true)
    {
        cin>>c;
        cin>>a;
        if(c=='u')
        {
            cin>>b;
            uni(a,b);
        }
        else if(c=='p')
        {
            cout<<findParent(a)<<endl;
        }
        else
        {
            cin>>b;
            if(sameSet(a,b))
                cout<<"They are connected"<<endl;
            else
                cout<<"They aren't connected"<<endl;
        }
    }

}

