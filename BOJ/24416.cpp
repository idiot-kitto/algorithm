#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int ans1, ans2, f[41];

int fib(int k) {
    if (k == 1 || k == 2) return 1; 
    else { ans1++; return (fib(k - 1) + fib(k - 2)); }
}

int fibonacci(int k) {
    f[1] = 1; f[2] = 1;
    for(int i=3 ; i<=k ; ++i) { f[i] = f[i-1] + f[i-2]; ans2++; } 
    return f[k];
}

int main(){fastio
    int n; cin >> n; fib(n); fibonacci(n);
    cout << ans1 + 1 << ' ' << ans2;
    return 0;
}