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

int n, id;
vi cost(101), v[101], cycle(101, 0), vis(101, 0);
vvi SCC;
stack<int> st;

int go(int k) {
    cycle[k] = ++id;
    st.push(k);
    int pa = cycle[k];
    for(auto next : v[k]) {
        if(!cycle[next]) pa = min(pa, go(next));
        else if(!vis[next]) pa = min(pa, cycle[next]);
    }

    if(pa == cycle[k]) {
        vi scc;
        while(1) {
            int t = st.top(); st.pop();
            scc.pb(t);
            vis[t] = 1;
            if(t == k) break;
        } SCC.pb(scc);
    } return pa;
}

int main(){fastio
    cin >> n;
    for(int i=1 ; i<=n ; ++i) cin >> cost[i];
    for(int i=1 ; i<=n ; ++i) {
        string s; cin >> s;
        for(int j=1 ; j<=n ; ++j) if(s[j-1] == '1') v[i].pb(j);
    }
    for(int i=1 ; i<=n ; ++i) if(!cycle[i]) go(i);

    int ans = 0;
    for(auto scc : SCC) {
        int tmp = 1e9;
        for(auto a : scc) tmp = min(tmp, cost[a]);
        ans += tmp;
    } cout << ans;

    return 0;
}