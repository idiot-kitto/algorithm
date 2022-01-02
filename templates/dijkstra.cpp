#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back

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
    int n, m; cin >> n >> m; // node 개수 n, edge 개수 m 입력
    vector<vpll> v(n+1); // 노드 시작 번호에 따라 바뀔 수 있음. ex) 0번 노드 시작 : v(n), 1번 노드 시작 : v(n+1)
    for(int i=0 ; i<m ; ++i) {
        int from, to, weight; cin >> from >> to >> weight; // 시작 노드 from, 도착 노드 to, 가중치 weight 입력
        v[from].pb({to, weight}); // from 벡터에 {to, weight} 삽입. 어디서 어디로 갈 수 있는지 넣어주는 부분.
        v[to].pb({from, weight}); // 단방향일 경우 생략, 양방향일 경우 같은 방식으로 삽입.
    }
    
    // 가중치란 시간, 거리 등이 될 수 있다.
    vl weight(n+1, 1e18); // 시작 노드(start_node)로 부터 도착 노드(destination_node)로 가는 최소 가중치를 담는 벡터.
    priority_queue<pll, vpll, greater<>> pq; // 작은 가중치부터 앞에 오도록 하는 오름차순 우선순위 큐
    pq.push({weight[start_node] = 0, start_node}); // 우선순위 큐에 {가중치, 시작 노드}로 넣어주는데, 이는 우선순위 큐가 pair의 첫번째 인자부터 정렬되는 특징 + 
                                                   // 다익스트라는 작은 가중치부터 갱신해야 하기 때문이다.
    
    while(!pq.empty()) { // 우선순위 큐가 빌 때까지
        ll cur_weight = pq.top().first, cur_node = pq.top().second; pq.pop(); // 첫번째 인자 : cur_weight : 현재 가중치
                                                                              // 두번째 인자 : cur_node : 현재 노드
        if(dist[cur_node] < cur_weight) continue; // 지금 갱신해야 하는 값이 이미 저장된 값보다 크다면 갱신할 필요가 없으므로 다음 순서로 넘어간다.
        for(auto &[to, to_weight] : v[cur_node]) { // 현재 노드(cur_node)로부터 갈 수 있는 다음 노드(to)와 다음 노드로 가기 위한 가중치(to_weight) 에 대한 반복문.
                                                   // js의 구조분해할당같은 C++의 방식.
            ll next_weight = cur_weight + to_weight; // 다음 노드로 가는 가중치(next_weight) = 
                                                     // 시작 노드부터 현재 노드까지 오는 가중치(cur_wiehgt) + 현재 노드에서 다음 노드로 가기 위한 가중치(to_weight)
            if(next_weight < weight[to]) pq.push({weight[to] = next_weight, to}); // 만약 그 값이 현재 저장된 값보다 작다면 갱신하고, (weight[to] = next_weight)
                                                                                  // 그 다음 노드로부터 최소 가중치를 갱신해나가기 위해 우선순위 큐에 {가중치, 다음 노드} 삽입.
        }
    } cout << weight[destination_node]; // 도착 노드 최소 가중치 출력.
    
    return 0;
}
