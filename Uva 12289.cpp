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
typedef pair<int,int> ii;


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

map<int,int> mp;
bool comp(const int &a,const int &b)
{
    if(mp[a]<mp[b])
        return true;
    else if(mp[a]==mp[b])
        return a<b;
    else
        return false;
}
int main()
{
    dance();
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(s.size()==5)
            cout<<3<<endl;
        else if((s[0]=='o'&&s[1]=='n')||(s[0]=='o'&&s[2]=='e')||(s[1]=='n'&&s[2]=='e'))
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }
    return 0;
}
