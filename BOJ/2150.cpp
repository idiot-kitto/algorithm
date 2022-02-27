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

vi v[10101];
vvi SCC;
int visited[10101], cycle[10101], n, m, ans, id, ok[10101];
stack<int> st;

int go(int k) {
    cycle[k] = ++id;
    st.push(k);
    int parent = cycle[k];
    for(auto next : v[k]) {
        if(!cycle[next]) parent = min(parent, go(next));
        else if(!visited[next]) parent = min(parent, cycle[next]);
    }

    if(parent == cycle[k]) {
        vi scc;
        while(1) {
            int t = st.top(); st.pop();
            scc.pb(t);
            visited[t] = 1;
            if(t == k) break;
        } SCC.pb(scc);
    } return parent;
}

void go2(int k) {
    ok[k] = 1;
    for(auto next : v[k]) if(!ok[next]) go2(next);
}

int main(){fastio
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        if(find(all(v[b]), a) == v[b].end()) v[b].pb(a);
    }

    for(int i=1 ; i<=n ; ++i) if(!cycle[i]) go(i);
    for(auto& scc : SCC) sort(all(scc));
    sort(all(SCC));

    cout << SCC.size() << '\n';
    for(auto scc : SCC) {
        for(auto a : scc) cout << a << ' ';
        cout << "-1\n";
    }

    return 0;
}
