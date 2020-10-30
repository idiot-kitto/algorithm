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
int n;
void func(int k)
{
    if(k == n){
        for(int i=0 ; i<k ; i++) cout << "____";
        cout << "\"재귀함수가 뭔가요?\"\n";
        for(int i=0 ; i<k ; i++) cout << "____";
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        for(int i=0 ; i<k ; i++) cout << "____";
        cout << "라고 답변하였지.\n";
        return;
    }
    for(int i=0 ; i<k ; i++) cout << "____";
    cout << "\"재귀함수가 뭔가요?\"\n";
    for(int i=0 ; i<k ; i++) cout << "____";
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    for(int i=0 ; i<k ; i++) cout << "____";
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    for(int i=0 ; i<k ; i++) cout << "____";
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    func(k+1);
    for(int i=0 ; i<k ; i++) cout << "____";
    cout << "라고 답변하였지.\n";
}
int main(){fastio
    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    func(0);
    return 0;
}
