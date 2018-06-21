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

/*
Here the functions you are looking for
*/
int Find(string main,string s)
{
    int n=s.size(); //store the size of word which i look for
    for(int i=0;i<main.size()-n;i++)
    {
        string s2=main.substr(i,n);// make a substring from the current position with
        //the same size of the word which i look for
        //if the are identical return the position
        if(s2==s)
            return i;
    }
    //word not found so return -1
    return -1;
}
int countO(string main,string s)
{
    int n=s.size(),c=0;
    for(int i=0;i<=main.size()-n;)
    {
        string s2=main.substr(i,n);
        if(s2==s)
            {
                i+=n;//if i found the word i will skip all (n) next letters
                c++;
            }
        else
            i++;// if i did not find the word i will move only one step forward
    }
    return c;
}
int main()
{
    dance();

    int l;
    while(true)
    {
        cin>>l;
        if(l==0)break;
        string s;
        cin>>s;
        int mn=INT_MAX,r=-1,d=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='Z')
            {
                mn=0;
                break;
            }
            else if(s[i]=='R')
            {
                if(d!=-1)
                    mn=min(mn,abs(i-d));
                d=-1;
                r=i;
            }
            else if(s[i]=='D')
            {
                if(r!=-1)
                    mn=min(mn,abs(i-r));
                r=-1;
                d=i;
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}
