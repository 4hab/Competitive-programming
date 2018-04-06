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
    int memory;
    int mx=0;
    vector<int> res;
    void perm(vector<int> songs,vector<int> cd,int pos,int busy_memory)
    {
        if(busy_memory>memory)
            return;
        if(busy_memory>mx)
        {
            mx=busy_memory;
            res=cd;
        }
        for(int i=pos;i<songs.size();i++)
        {
            cd.push_back(songs[i]);
            perm(songs,cd,i+1,busy_memory+songs[i]);
            cd.pop_back();
        }
    }
int main ()
{
     dance();
     while(cin>>memory)
     {
         int n;
         cin>>n;
         vector<int> v(n),cd;
         for(int i=0;i<n;i++)
         {
             cin>>v[i];
         }
         perm(v,cd,0,0);
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<' ';
        }
        cout<<"sum:"<<mx<<endl;

        mx=0;
        res.clear();
     }
     return 0;
}
