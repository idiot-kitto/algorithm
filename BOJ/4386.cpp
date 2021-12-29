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
const int mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

struct DSU {
    int n; vi pa;
    DSU(int _n):n(_n) { pa.resize(n+1); iota(all(pa), 0); }
    int find(int a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); }
    void merge(int a, int b) { pa[find(b)] = find(a); }
    int check(int a, int b) { return find(a) == find(b); }
};

int main(){fastio
    int n; cin >> n;
    vector<pair<double,double>> tmp;
    for(int i=0 ; i<n ; ++i) {
        double a, b; cin >> a >> b;
        tmp.pb({a,b});
    }
    vector<pair<double,pair<double,double>>> v;
    for(int i=0 ; i<n-1 ; ++i)
        for(int j=i+1 ; j<n ; ++j) {
            double a = tmp[i].first, b = tmp[i].second;
            double c = tmp[j].first, d = tmp[j].second;
            v.pb({sqrt(pow(a-c,2) + pow(b-d,2)), {i, j}});
        }
    sort(all(v));

    DSU dsu(n);
    double ans = 0;
    int cnt = 0;
    for(int i=0 ; i<v.size() ; ++i) {
        double cost = v[i].first;
        int x = (int)v[i].second.first, y = (int)v[i].second.second;
        if(dsu.check(x,y)) continue;
        dsu.merge(x,y);
        ans += cost, cnt++;
        if(cnt == n - 1) break;
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}
