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

#define SIZE 1010

vi v[SIZE];
int val[SIZE], cnt[SIZE], ans[SIZE];

// 위상정렬은 유향 비순환 그래프에서 진행된다.

int main(){fastio
    int n; cin >> n; // node 개수 n 선언
    for(int i=1 ; i<=n ; ++i) { // 문제에서 정의한 "순서"에 따라 입력을 받아준다.
        int prev_node, next_node; cin >> prev_node >> next_node; 
        v[prev_node].pb(next_node); // prev_node -> next_node 그래프가 만들어지는 과정
        cnt[next_node]++; // next_node로 들어오는 간선의 개수를 증가시켜줌. 즉 cnt[N]은 N번 노드로 들어오는 간선의 개수를 담은 배열.
    }
    
    queue<int> q;
    for(int i=1 ; i<=n ; ++i) if(!cnt[i]) q.push(i); // 들어오는 간선의 개수가 없다면 Queue에 넣어준다.
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next : v[cur]) {
            if(!(--cnt[next])) q.push(next); // cur -> next 로 가는 간선을 지우면서 next로 들어오는 간선의 수가 0이 되면 Queue에 넣어준다.
        }
    } // 보통 문제 해결을 위한 로직은 while문 내부(44~49줄 사이)에 들어간다.
    
    for(int i=1 ; i<=n ; ++i) cout << ans[i] << '\n';
           
    return 0;
}
