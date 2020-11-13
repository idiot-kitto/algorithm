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

int main(){fastio
    int n, k = -1; cin >> n; vi v(n);
    for(int i=0 ; i<n ; i++) cin >> v[i];
    int a = 0, b = 0;
    for(int i=0 ; i<n-1 ; i++) if(v[i] > v[i+1]) a++;
    for(int i=0 ; i<n-1 ; i++) if(v[i] < v[i+1]) b++;
    if(a == 0 || b == 0) {cout << 0; return 0;}
    else if(a == 1 && b == 1){
        int x = 0, y = 0;
        for(int i=0 ; i<n-1 ; i++) if(v[i] > v[i+1] && v[0] >= v[v.size()-1]) x = i+1;
        for(int i=0 ; i<n-1 ; i++) if(v[i] < v[i+1] && v[0] <= v[v.size()-1]) y = i+1;
        if(x && y){cout << min(x,y); return 0;}
        else if(x){cout << x; return 0;}
        else if(y){cout << y; return 0;}
        else{cout << -1; return 0;}
    }else if(a == 1){
        for(int i=0 ; i<n-1 ; i++) if(v[i] > v[i+1] && v[0] >= v[v.size()-1]){cout << i+1; return 0;}
    }else if(b == 1){
        for(int i=0 ; i<n-1 ; i++) if(v[i] < v[i+1] && v[0] <= v[v.size()-1]){cout << i+1; return 0;}
    }
    cout << -1;
    return 0;
}
