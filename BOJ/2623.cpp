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

vi v[1010];
int line[1010], ans[1010];

int main(){fastio
    int n, m; cin >> n >> m;
    for(int i=0 ; i<m ; ++i) {
        int k; cin >> k;
        int prev;
        for(int j=0 ; j<k ; ++j) {
            int a; cin >> a;
            if(j){
                line[a]++;
                v[prev].pb(a);
            } prev = a;
        }
    }
    queue<int> q;
    for(int i=1 ; i<=n ; ++i) if(!line[i]) q.push(i);
    for(int i=0 ; i<n ; ++i) {
        if(q.empty()) { cout << 0; return 0;}
        int cur = q.front(); q.pop();
        ans[i] = cur;
        for(auto next : v[cur]) {
            if(!(--line[next])) q.push(next);
        }
    }
    for(int i=0 ; i<n ; ++i) cout << ans[i] << '\n';

    return 0;
}
