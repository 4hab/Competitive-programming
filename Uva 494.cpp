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

int main()
{
    dance();
    string s;
    while(getline(cin,s))
    {
        int total=0;
        bool c=true;
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i])&&c)
            {
                total++;
                c=false;
            }
            else if(!isalpha(s[i]))
                c=true;
        }
        cout<<total<<endl;
    }
    return 0;
}
