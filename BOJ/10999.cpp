#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, a, b, c, d;
vector<ll> arr(1000001), tree(4000001);

ll init(int node, int start, int end)
{
    int mid = (start + end) / 2;
    if(start == end) return tree[node] = arr[start];
    else return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int index, ll diff)
{
    if(start > index || index > end) return;
    tree[node] += diff;
    if(start != end){
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll sum(int node, int start, int end, int left, int right)
{
    if(left > end || right <start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    init(1, 0, n-1);
    for(int i=0 ; i<m+k ; i++){
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            for(int j=b ; j<=c ; j++) update(1, 0, n-1, j-1, d);
        }
        else if(a == 2){
            cin >> b >> c;
            cout << sum(1, 0, n-1, b-1, c-1) << "\n";
        }
    }
    return 0;
}


/*
내가 공부했던 세그먼트 트리로만 구현했을때 TLE가 났다.
구간 1~3을 업데이트 하겠다고 하면 1번째, 2번째, 3번째 값이 각각 변할때 update가 되게 했기 때문에
O(NlogN)의 시간이 걸리기 때문이었다. 그래서 https://www.acmicpc.net/blog/view/26 에서 lazy propagation 을 이용한
구간의 값을 변경시킬때 효율적인 알고리즘을 사용하여 시간을 단축하여 AC를 받을 수 있었다.
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, a, b, c;
vector<ll> arr(1000001), tree(4000001), lazy(4000001);

ll init(int node, int start, int end)
{
    int mid = (start + end) / 2;
    if(start == end) return tree[node] = arr[start];
    else return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end)
{
    if(lazy[node]){ // lazy[node] 가 0 이 아니면
        tree[node] += (end - start + 1) * lazy[node]; // update 되는 구간 개수만큼 곱해서 구간 노드에 더해준다.
        if(start != end){ // 리프노드가 아니면
            lazy[node * 2] += lazy[node]; // 좌측 자식노드에,
            lazy[node * 2 + 1] += lazy[node]; // 우측 자식노드에 lazy를 물려준다.
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right, ll diff)
{
    update_lazy(node, start, end);
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        tree[node] += (end - start + 1) * diff;
        if(start != end){
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        } return;
    }
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff);
    update_range(node * 2 + 1, mid + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(int node, int start, int end, int left, int right)
{
    update_lazy(node, start, end);
    if(left > end || right <start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    init(1, 0, n-1);
    for(int i=0 ; i<m+k ; i++){
        cin >> a;
        if(a == 1){
            ll d;
            cin >> b >> c >> d;
            update_range(1, 0, n-1, b-1, c-1, d);
        }
        else if(a == 2){
            cin >> b >> c;
            cout << sum(1, 0, n-1, b-1, c-1) << "\n";
        }
    }
    return 0;
}


/*
lazy propagation이란, 구간의 값을 변경할 때 꼭 필요한 때가 오기 전까지 업데이트를 미뤄두는 방법이다.
여기서 lazy 배열이 업데이트를 미룰 때 사용하는 배열이다. lazy[i]는 i번 노드가 담당하는 구간에 더해져야 할 수가 저장되어 있다.
87번, 104번 줄을 보면 update_lazy(node, start, end); 가 있다. update 또는 sum 을 진행하기 전에 lazy에 저장되어 있는 값들을 수행하고(구간에 맞는)
그 다음 작업을 하라는 의미이기 때문에 수행에 꼭 필요한 구간이 아닌 경우 처리하지 않기때문에 수행시간이 줄어든다.
*/
