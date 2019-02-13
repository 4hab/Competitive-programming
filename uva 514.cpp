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
int b[1001];
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
        while(true)
        {
            bool ok=true;
            queue<int> q;
            stack<int> s;
            for(int i=1;i<=n;i++)q.push(i);
            cin>>b[1];
            if(b[1]==0)
            {
                cout<<endl;
                break;
            }
            for(int i=2; i<=n; i++)
                cin>>b[i];
            for(int i=1;i<=n&&ok;i++)
            {
                if(q.empty())
                {
                    if(s.top()!=b[i])
                        ok=false;
                    s.pop();
                }
                else
                {
                    if(q.front()==b[i])
                        q.pop();
                    else if(!s.empty()&&s.top()==b[i])
                        s.pop();
                    else
                    {
                        ok=false;
                        while(!q.empty()&&!ok)
                        {
                            s.push(q.front());
                            q.pop();
                            if(s.top()==b[i])
                            {
                                s.pop();
                                ok=true;
                            }
                        }
                    }

                }
            }
            if(ok)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

        }
    }
}

