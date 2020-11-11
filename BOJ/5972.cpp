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
    int n, m; cin >> n >> m;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<pii> v[n+1];
    vi dist(n+1, INT_MAX);
    vb check(n+1,false);
    for(int i=0 ; i<m ; i++){
        int a, b, c; cin >> a >> b >> c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        int k = pq.top().second;
        pq.pop();
        if(!check[k]){
            check[k] = true;
            for(int i=0 ; i<v[k].size() ; i++){
                int next = v[k][i].first;
                if(dist[next] > dist[k] + v[k][i].second){
                    dist[next] = dist[k] + v[k][i].second;
                    pq.push({dist[next], next});
                }
            }
        }
    }
    cout << dist[n];
    return 0;
}
