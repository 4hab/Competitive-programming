#include<bits/stdc++.h>

using namespace std;

#define all(v)              v.begin(),v.end()
#define allr(v)             v.rbegin(),v.rend()
#define sz(v) (int)         v.size()
#define loop(i,from,to)     for(int i=from;i<=to;i++)
#define loopr(i,from,to)    for(int i=from;i>=to;i--)
#define pb(x)               push_back(x)
#define mkpr(x,y)                make_pair(x,y)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef pair<int,int> ii;

int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
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

int inv_count=0;
void Merge(vector<int> &v,int l,int mid,int r)
{
    vector<int> res(v.size());
    int left=l,right=mid;
    int i=l;
    while(left<mid&&right<=r)
    {
        if(v[left]<=v[right])
            res[i++]=v[left++];
        else
        {
            res[i++]=v[right++];
            inv_count+=(mid-left);
        }
    }
    while(left<=mid)
        res[i++]=v[left++];
    while(right<=r)
        res[i++]=v[right++];
    for(int k=l; k<=r; k++)
        v[k]=res[k];
}
void merge_sort(vector<int> &v,int l,int r)
{
    if(l==r)
        return;
    int mid=(l+r)/2;
    merge_sort(v,l,mid);
    merge_sort(v,mid+1,r);
    Merge(v,l,mid+1,r);

}
int minswap(vector<pair<ll,int> >&v,int n)
{
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || v[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            j = v[j].second;
            cycle_size++;
        }

        ans += (cycle_size - 1);
    }
    return ans;
}

bool isPrime(int n)
{

    if(n==2)
        return true;
    if(n<2||n%2==0)
        return false;
    for(int i=3; i*i<=n; i+=2)
        if(n%i==0)
            return false;
    return true;
}
void line(int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(i>=n/2-x/2&&i<=n/2+x/2)
            cout<<'D';
        else
            cout<<'*';
    }
}
void sorboan(int n)
{
    if(n>=5)
    {
        cout<<"-O|";
        n-=5;
    }
    else
        cout<<"O-|";
    int k=4;
    while(n--&&k--)
        cout<<"O";
    cout<<"-";
    while(k--)
        cout<<"O";
    cout<<endl;
}
int o=0;
map<int,int> mp;
void pf(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            mp[i]++;
            n/=i;
            if(mp[i]%2)
                o++;
            else
                o--;
            i--;
        }
    }
    if(n>1)
    {
        mp[n]++;
        if(mp[n]%2)
            o++;
        else
            o--;
    }
}
int N=1000000;
bool p[1000001];
void makePrimes()
{
    int lim=sqrt(N);
    memset(p,true,sizeof(p));
    for(int i=2;i<=lim;i++)
    {
        if(p[i])
        {
            for(int j=i*2;j<=N;j+=i)
                p[j]=false;
        }
    }
}
int sod(int x)
{
    int sum=0;
    while(x)
    {
       sum+=x%10;
       x/=10;
    }
    return sum;
}
int dprime[1000001];
int main()
{
    int t;
    scanf("%d",&t);
    dprime[0]=dprime[1]=0;
    makePrimes();
    for(int i=2;i<=N;i++)
    {
        dprime[i]=dprime[i-1];
        if(p[i]&&p[sod(i)])
            dprime[i]++;
    }
    while(t--)
    {
        int l,r,c=0;
        scanf("%d %d",&l,&r);
        c=dprime[r]-dprime[l-1];
        cout<<c<<endl;
    }
    return 0;
}
