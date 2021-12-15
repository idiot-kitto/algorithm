#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100001

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const long long mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int n, m;
vi v, check;
set<vi> st;

void go(vi &vv) {
    if(vv.size() == m) {
        st.insert(vv);
        return;
    }

    for(int i=0 ; i<n ; i++) {
        if(!check[i]) {
            check[i] = 1;
            vv.pb(v[i]);
            go(vv);
            check[i] = 0;
            vv.pop_back();
        }
    }
}

int main(){fastio
    cin >> n >> m;
    v = vi(n, 0);
    check = vi(n, 0);
    sort(all(v));

    for(int i=0 ; i<n ; i++) cin >> v[i];
    vi vv;
    go(vv);

    for(auto vvv : st) {
        for(auto k : vvv) cout << k << ' ';
        cout << '\n';
    }

    return 0;
}
