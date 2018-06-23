#include<bits/stdc++.h>

using namespace std;

#define all(v)              v.begin(),v.end()
#define allr(v)             v.rbegin(),v.rend()
#define sz(v) (int)         v.size()
#define loop(i,from,to)     for(int i=from;i<=to;i++)
#define loopr(i,from,to)    for(int i=from;i>=to;i--)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;


void dance()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
template<typename t>
void printV(vector<t> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int countSetBits(ll n)
{
    int c= 0;
    while (n)
    {
        c+= n & 1;
        n >>= 1;
    }
    return c;
}
vector<vector<int> >g;
vector<bool> visited;
int n,c=0;
void dfs(int i)
{
    c++;
    visited[i]=true;
    if(i==n+1)
        return;
    for(int j=0; j<g[i].size(); j++)
    {
        int ch=g[i][j];
        if(!visited[ch])
            dfs(ch);
    }
}
int main()
{
    dance();
    string s;
    while(getline(cin,s))
    {
        //if(s=="0")break;
        int l=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==' ')
            {
                reverse(s.begin()+l,s.begin()+i);
                l=i+1;
            }
        }
        reverse(s.begin()+l,s.begin()+s.length());
        cout<<s;
        cout<<endl;
    }
    return 0;
}

/*
5 4 1
2 3
3 2
4 5
5 4

*/
    
