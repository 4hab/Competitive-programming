#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) (int)sizeof(v)
#define pb(x) push_back(x)
#define mkpr(x, y) make_pair(x, y)
#define oo INT_MAX
#define noo INT_MIN
#define forn(i, n) for (ll i = 0; i < n; i++)
#define fore(i, b, e) for (ll i = b; i <= e; i++)
#define ford(i, n) for (ll i = n - 1; i >= 0; i--)
#define EPS 1e-9
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int kx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int ky[] = {1, -1, 1, -1, 2, -2, 2, -2};

void dance() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void file() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

template <typename t> void printV(vector<t> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << endl;
}

bool isPrime(ll n) {

  if (n == 2)
    return true;
  if (n < 2 || n % 2 == 0)
    return false;
  for (ll i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

bool prime[100001];
void seive() {
  memset(prime, true, sizeof(prime));
  prime[1] = false;
  for (int i = 2; i <= 100000; i++) {
    if (prime[i])
      for (int j = i + i; j <= 100000; j += i) {
        prime[j] = false;
      }
  }
}

/**
 *****code begins here*****
 **/
ll MOD = 1000000007;

int main() {
  dance();
  int t;
  cin>>t;
  while(t--)
  {
      int n,mx=0,mn=oo;
      cin>>n;
      while(n--)
      {
          int x;
          cin>>x;
          mn=min(mn,x);
          mx=max(mx,x);
      }
      cout<<(mx-mn)*2<<endl;
  }
}
