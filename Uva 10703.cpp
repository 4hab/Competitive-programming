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
	while(true)
    {
        int w,h,n;
        cin>>w>>h>>n;
        if(w==0)
            break;
        int a,b,x,y;
        vector<vector<bool> > v(w+1,vector<bool>(h+1,true));
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>x>>y;
            if(a>x)
                swap(a,x);
            if(b>y)
                swap(b,y);
            for(int j=a;j<=x;j++)
                for(int k=b;k<=y;k++)
                    v[j][k]=false;
        }
        int sum=0;
        for(int i=1;i<=w;i++)
            for(int j=1;j<=h;j++)
                if(v[i][j]) sum++;
        if(sum==0)
            cout<<"There is no empty spots."<<endl;
        else if(sum==1)
            cout<<"There is one empty spot."<<endl;
        else
            cout<<"There are "<<sum<<" empty spots."<<endl;
    }

	return 0;
}
/*
5
1 2 3 4 5
4
1 1
2 2
1 3
5 5
*/
