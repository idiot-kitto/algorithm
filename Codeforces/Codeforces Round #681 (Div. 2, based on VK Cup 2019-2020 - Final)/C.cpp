#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100001

typedef long long ll;
typedef vector<int> vi;
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
const int mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

/* seg_tree
ll tree[4*SIZE];
ll init(ll node, ll start, ll end){
    ll mid = (start + end) / 2;
    if(start == end) return tree[node] = v[start];
    else return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
void update(ll node, ll start, ll end, ll index, ll diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}*/
int t;
int main(){fastio
    cin >> t;
    while(t--){
        int n; cin >> n; vector<pll> v(n);
        for(int i=0 ; i<n ; i++) cin >> v[i].first;
        for(int i=0 ; i<n ; i++) cin >> v[i].second;
        sort(all(v),[](const pll &v1, const pll &v2){
             if(v1.first == v2.first) return v1.second < v2.second;
             return v1.first > v2.first;});
        int idx = INT_MAX; ll ans = 0;
        for(int i=0 ; i<n ; i++){
            if(ans + v[i].second < v[i].first) ans += v[i].second;
            else {idx = i; break;}
        }
        if(idx == INT_MAX) cout << ans << '\n';
        else cout << max(ans, v[idx].first) << '\n';
    }
    return 0;
}
/*
7 5 4 3
1 4 2 2

4 3 2 1
3 3 3 3

2 1
10 10

10 10
1 2
*/
