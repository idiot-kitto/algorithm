#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a, b;
vector<ll> arr(100001), tree(400001);

ll init(int node, int start, int end)
{
    int mid = (start + end) / 2;
    if(start == end) return tree[node] = arr[start];
    else return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid+1, end));
}

ll find_min(int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    ll n1 = find_min(node * 2, start, mid, left, right);
    ll n2 = find_min(node * 2 + 1, mid + 1, end, left, right);
    if(!n1) return n2;
    else if(!n2) return n1;
    else return min(n1, n2);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    init(1, 0, n-1);

    while(m--){
        cin >> a >> b;
        cout << find_min(1, 0, n-1, a-1, b-1) << "\n";
    }

    return 0;
}

/*

리프노드에서 상위노드로 올라갈 때, 그 구간에 대한 최소값을 저장하도록 tree[node]를 만들었다.
test case를 예시로 보자.

                  5
         30                5
    30       38        20      5
  30  100  38  50    51  20  81  5
75  30             51  52

init()을 하면 이런 형태로 트리가 만들어지게 되는데, 여기서 arr는 75 30 100 38 50 51 52 20 81 5 이고, 상위 노드는 구간의 최소값이 저장된다.
a = 3, b = 5 (즉 구간 2~4 에서 최소값을 찾아라.)라고 하면, 34번째 줄에서 find_min(1(node), 0(start), 9(end), 2(left), 4(right))가 전달된다.
조건문들을 넘어가고 n1 = find_min(2(node), 0(start), 4(end), 2(left), 4(right)) / n2 = find_min(3(node), 5(start), 9(end), 2(left), 4(right)) 를 재귀로 돌게된다. 
n2 = find_min(3(node), 5(start), 9(end), 2(left), 4(right))은 첫번째 조건문에서 0 으로 return 되고, 결국 22번째 줄에서 n1을 return 하게 되는데, 이것은 
구간 2~4에서 최소값은 루트노드에서 좌측 자식노드에서 찾을 수 있다는 것을 의미한다. 더 진행해보자.
n1 = find_min(2(node), 0(start), 4(end), 2(left), 4(right)) "안"에서,
----------------------------------------------------------------------- 다른 n1, n2를 구별하기 위한 '\n'
n1 = find_min(4(node), 0(start), 2(end), 2(left), 4(right)) 이고, n2 = find_min(5(node), 3(start), 4(end), 2(left), 4(right)) 이다.
여기서 n2 를 잘 보면, 구간 2~4 에서 3(start)~4(end)가 포함되어 있는 것을 볼 수 있다. 이 경우 두번째 조건문에서 tree[5] (=tree[node]) 를 return 하는데, 같은 방식으로
n1 = find_min(4(node), 0(start), 2(end), 2(left), 4(right)) 에서도 tree[9] 를 return 하여 결국에는 tree[5] (38) 과 tree[9] (100) 을 비교하여 38을 출력하는 방식이다.

단순한 반복문으로 해결한다면 O(N)으로 TLE가 나게되지만 세그먼트 트리를 이용하여 O(logN)으로 AC를 받을 수 있다.

*/
