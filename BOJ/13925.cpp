#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;
int n, m, query, x, y, v;
vector<ll> arr(100001), tree(400001), lazy_add(400001), lazy_mul(400001);

ll init(int node, int start, int end)
{
    int mid = (start + end) / 2;
    if(start == end) return tree[node] = arr[start];
    else return tree[node] = (init(node * 2, start, mid) + init(node * 2 + 1, mid + 1 ,end)) % M;
}

void update_lazy(int node, int start, int end)
{
    if(lazy_add[node] || lazy_mul[node] != 1){
        tree[node] = (lazy_mul[node] * tree[node] ) % M;
        tree[node] = (tree[node] + (((end - start + 1) * lazy_add[node]) % M)) % M;
        if(start != end){
            lazy_mul[node * 2] = (lazy_mul[node * 2] * lazy_mul[node]) % M;
            lazy_mul[node * 2 + 1] = (lazy_mul[node * 2 + 1] * lazy_mul[node]) % M;
            lazy_add[node * 2] = (lazy_add[node * 2] * lazy_mul[node]) % M;
            lazy_add[node * 2 + 1] = (lazy_add[node * 2 + 1] * lazy_mul[node]) % M;
            lazy_add[node * 2] = (lazy_add[node * 2] + lazy_add[node]) % M;
            lazy_add[node * 2 + 1] = (lazy_add[node * 2 + 1] + lazy_add[node]) % M;
        }
        lazy_mul[node] = 1;
        lazy_add[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right, ll diff, int query)
{
    update_lazy(node, start, end);
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        if(query == 1){
            tree[node] = (tree[node] + ((end - start + 1) * diff) % M) % M;
            if(start != end){
                lazy_add[node * 2] = (lazy_add[node * 2] + diff) % M;
                lazy_add[node * 2 + 1] = (lazy_add[node * 2 + 1] + diff) % M;
            } return;
        }
        else if(query == 2){
            tree[node] = (tree[node] * diff) % M;
            if(start != end){
                lazy_mul[node * 2] = (lazy_mul[node * 2] * diff) % M;
                lazy_mul[node * 2 + 1] = (lazy_mul[node * 2 + 1] * diff) % M;
                lazy_add[node * 2] = (lazy_add[node * 2] * diff) % M;
                lazy_add[node * 2 + 1] = (lazy_add[node * 2 + 1] * diff) % M;
            } return;
        }
        else if(query == 3){
            tree[node] = ((end - start + 1) * diff) % M;
            if(start != end){
                lazy_mul[node * 2] = 0;
                lazy_mul[node * 2 + 1] = 0;
                lazy_add[node * 2] = diff;
                lazy_add[node * 2 + 1] = diff;
            } return;
        }
    }
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff, query);
    update_range(node * 2 + 1, mid + 1, end, left, right, diff, query);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % M;
}

ll sum(int node ,int start, int end, int left, int right)
{
    update_lazy(node ,start, end);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return ((sum(node * 2, start, mid, left, right) % M) + (sum(node * 2 + 1, mid + 1, end, left, right)) % M) % M;
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    for(int i=0 ; i<400001 ; i++) lazy_mul[i] = 1;
    init(1, 0, n-1);

    cin >> m;
    for(int i=0 ; i<m ; i++){
        cin >> query;
        if(query == 4){
            cin >> x >> y;
            cout << sum(1, 0, n-1, x-1, y-1) << "\n";
        }
        else {
            cin >> x >> y >> v;
            update_range(1, 0, n-1, x-1, y-1, v, query);
        }
    }
    return 0;
}

/*
세그먼트 트리와 lazy propagation의 응용문제다. 10999번과 비슷할거라고 생각하고 비슷한 틀을 만들어 풀었는데 다이아문제여서 그런지 단순하지 않았다.
처음엔 lazy를 하나만 만들고 시작했는데 더해주는 lazy와 곱해주는 lazy를 다르게 만들어 주어야 했다.
lazy 배열을 하나로 두고 하면, 쿼리 1 2 3번 중 부분적으로만 작동하고 완전한 구현을 할 수 없었다.
거의 3시간정도 걸려서 문제를 풀었는데, 잔실수가 많았다. 예를들면 곱해주는 lazy에는 모든 원소를 1로 초기화 해주어야 한다.
쿼리 2번에서 어떤수를 곱해주고자 하면 그 피연산자가 0 이면 결국 0 이 되기때문에.. 
그리고 17 번줄의 lazy_mul[node] != 1 를 !lazy_mul[node] 이라 쓰고 여기서 시간을 많이 잡아먹었다 ㅠㅠ
복잡한 문제를 풀때는 최대한 헷갈리는 코딩은 자제해야 할것같다.
*/
