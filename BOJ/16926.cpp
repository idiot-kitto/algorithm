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
int n, m, r;
vvi v;
int main(){fastio
    cin >> n >> m >> r; v = vvi(n+1,vi(m+1));
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++) cin >> v[i][j];
    while(r--){
        pii d1 = {1,1}, d2 = {n,1}, d3 = {n,m}, d4 = {1,m};
        while((d1.first < d2.first) && (d1.second < d4.second)){
            int tmp = v[d2.first][d2.second];
            for(int i=d2.first ; i>d1.first ; i--) v[i][d2.second] = v[i-1][d2.second];
            for(int i=d1.second; i<d4.second ; i++) v[d1.first][i] = v[d1.first][i+1];
            for(int i=d4.first ; i<d3.first ; i++) v[i][d4.second] = v[i+1][d4.second];
            for(int i=d3.second ; i>d2.second ; i--) v[d3.first][i] = v[d3.first][i-1];
            v[d2.first][d2.second+1] = tmp;
            d1.first += 1; d1.second += 1;
            d2.first -= 1; d2.second += 1;
            d3.first -= 1; d3.second -= 1;
            d4.first += 1; d4.second -= 1;
        }
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++) cout << v[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
