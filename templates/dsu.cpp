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

struct DSU { // Disjoint Set Union
    int n; vi pa; // pa : parents
    DSU(int _n):n(_n) { pa.resize(n+1); iota(all(pa), 0); } // n+1개의 노드의 parents 값 선언, iota -> pa[1] = 1, pa[2] = 2, pa[3] = 3 ... 이런식의 함수이다.
    int find(int a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); } // a의 최상위 부모를 반환한다.
    void merge(int a, int b) { pa[find(b)] = find(a); } // a 노드와 b 노드의 부모를 같게 만드는 함수
    int check(int a, int b) { return find(a) == find(b); } // a 노드와 b 노드의 부모가 같은지 확인한다.
};

int main(){fastio
    int n, m; cin >> n >> m; // node 개수 n, edge 개수 m 입력
    DSU dsu(n); // n개의 노드 선언

    for(int i=0 ; i<m ; ++i) {
        int node1, node2; cin >> node1 >> node2;
        dsu.merge(node1, node2); // node1 집합(트리)과 node2 집합(트리)을 합친다.
    }

    int node1, node2; cin >> node1 >> node2; // node1 집합(트리)과 node2 집합(트리) 입력
    cout << dsu.find(node1) << ' ' << dsu.find(node2) << '\n'; // node1 집합(트리)과 node2 집합(트리)이 어느 집합에 속해있는지 확인한다.
    cout << dsu.check(node1, node2); // node1 집합(트리)과 node2 집합(트리)가 같은 집합인지 확인한다.

    return 0;
}
