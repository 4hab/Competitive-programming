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
vector<vector<int> >v;
vector<bool> visited(27,false);
vector<bool> visited2;
int n;
int dp[27][300001];
string s;
bool loop;
int dfs(char c,int i)
{
    if(i==n+1)
        return 0;
    if(visited2[i])
    {
        loop=true;
        return 0;
    }
    if(dp[c-'a'][i]!=-1)
        return dp[c-'a'][i];
    visited2[i]=true;
    int mx=0;
    for(int j=0; j<v[i].size(); j++)
    {
        mx=max(mx,dfs(c,v[i][j]));
    }
    if(s[i-1]==c)
        mx++;
    visited2[i]=false;
    return mx;
}
int main()
{
    dance();
    string s;
    set<string> st;
    while(cin>>s)
    {

        //if(s=="0")break;
        string w="";
        for(int i=0; i<s.length(); i++)
        {
            s[i]=tolower(s[i]);
            if(isalpha(s[i]))
                w+=tolower(s[i]);
            else if(w!="")
            {
                st.insert(w);
                w="";
            }
        }
        if(w!="")
            st.insert(w);
    }
    set<string>::iterator it=st.begin();
    while(it!=st.end())
    {
        cout<<*it<<endl;
        it++;
    }
    return 0;
}

/*
4 5
1 2
1 3
1 4
2 3
2 4

*/
