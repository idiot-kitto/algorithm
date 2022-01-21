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

int main(){fastio
    int n; cin >> n; vector<tuple<int, int, int>> v, ans;
    for(int i=0 ; i<n ; ++i) {
        int a, b, c; cin >> a >> b >> c;
        v.eb(a, b, c);
    } sort(all(v));

    for(auto k : v) {
        int a = get<0>(k), b = get<1>(k), c = get<2>(k);
        if(ans.empty()) ans.eb(a, b, c);
        else {
            int aa = get<0>(ans[ans.size() - 1]);
            int bb = get<1>(ans[ans.size() - 1]);
            int cc = get<2>(ans[ans.size() - 1]);
            
            if(a <= bb) {
                ans.pop_back();
                ans.eb(min(a, aa), max(b, bb), min(c, cc));
            } else ans.eb(a, b, c);
        }
    }

    cout << ans.size() << '\n';
    for(auto k : ans) cout << get<0>(k) << ' ' << get<1>(k) << ' ' << get<2>(k) << '\n';
    
    return 0;
}