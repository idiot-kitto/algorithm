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


int main(){fastio
    int n; cin >> n;
    vpll v;
    for(int i=0 ; i<n ; ++i) {
        ll a, b; cin >> a >> b;
        v.pb({a,b});
    }
    double ans = 0;

    auto calc = [&](pll x, pll y) {
        return x.first * y.second - x.second * y.first;
    };

    for(int i=0 ; i<n ; ++i) {
        if(i == n-1) ans += (double)(calc({v[i].first, v[i].second}, {v[0].first, v[0].second}) / 2.0);
        else ans += (double)(calc({v[i].first, v[i].second}, {v[i+1].first, v[i+1].second}) / 2.0);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(ans);

    return 0;
}

// 신발끈 공식 사용
