    #include<bits/stdc++.h>
    #include<iostream>
    #include<iomanip>
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

    ll Gcd(ll a, ll b){return !b ? a : Gcd(b, a % b);}
    void dance()
        {
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
        }
    bool isprime(int n)
    {
        if(n<=2)return true;
        else if(n%2==0) return false;
        for(int i=3;i*i<=n;i+=2)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
int inv_count=0;
    int Merge(int arr[],int left,int right,int mid)
    {
        vector<int> v;
        int l=left,r=mid+1;
        while(l<=mid&&r<=right)
        {
            if(arr[l]<=arr[r])
            {
                v.push_back(arr[l++]);
            }
            else
            {
                v.push_back(arr[r]);
                inv_count+=(mid-l+1);
                r++;
            }
        }
        while(l<=mid)v.push_back(arr[l++]);
        while(r<=right)v.push_back(arr[r++]);
        int pos=left;
        for(int i=0;i<v.size();i++)
        {
            arr[pos++]=v[i];
        }
        return inv_count;
    }

    void mergeSort(int arr[],int l,int r)
    {
        if(l<r)
        {
            int mid=(l+r)/2;

            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);

            Merge(arr,l,r,mid);
        }
    }
bool none=true;
set<vector<int> > a;
void p(vector<int> v)
{
    a.insert(v);
}
void printV(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        if(i>0)
            cout<<'+';
        cout<<v[i];
    }
    cout<<endl;
}
void perm(vector<int> v,vector<int> v2,int pos,int num,int sum)
{
    if(sum==num)
    {
        p(v2);
        none=false;
        return;
    }
    if(sum>num)
        return;
    for(int i=pos;i<v.size();i++)
    {
        v2.push_back(v[i]);
        perm(v,v2,i+1,num,sum+v[i]);
        v2.pop_back();
    }
}
int main ()
{
     dance();
     int n,x;
     while(true)
     {
         none=true;
         int m;
         cin>>m>>n;
         if(m==0)
            break;
        vector<int> v(n),v2;
         for(int i=0;i<n;i++)
         {
             cin>>v[i];
         }
         perm(v,v2,0,m,0);
         if(none)
         {
             cout<<"Sums of "<<m<<":"<<endl;
             cout<<"NONE"<<endl;
             continue;
         }
         set<vector<int> >::iterator it=a.end();it--;
         cout<<"Sums of "<<m<<":"<<endl;
         while(it!=a.begin())
            {
                printV(*it);
                it--;
            }
            printV(*it);
            a.clear();
     }
     return 0;
}
