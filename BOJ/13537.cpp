#include <bits/stdc++.h>
using namespace std;
int n, m, q, a, b, k;
vector<int> arr(100001), tree(400001);

int init(int node, int start, int end)
{
    int mid = (start + end) / 2;
    if(start == end) return tree[node] = arr[start] % 2;
    else return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, int k)
{
    if(start > idx || idx > end) return;
    tree[node] += k;
    if(start != end){
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, k);
        update(node * 2 + 1, mid + 1, end, idx, k);
    }
}

int query(int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    init(1, 0, n-1);

    cin >> m;
    for(int i=0 ; i<m ; i++){
        cin >> q;
        if(q == 1){
            cin >> a >> b;
            if(arr[a-1] % 2 == 0) k = (b % 2 == 0) ? 0 : 1;
            else k = (b % 2 == 0) ? -1 : 0;
            arr[a-1] = b;
            update(1, 0, n-1, a-1, k);
        }
        else if(q == 2){
            cin >> a >> b;
            cout << (b - a + 1) - query(1, 0, n-1, a-1, b-1) << "\n";
        }
        else if(q == 3){
            cin >> a >> b;
            cout << query(1, 0, n-1, a-1, b-1) << "\n";
        }
    }
    return 0;
}


/*
tree의 리프노드에 홀수인지 검사하여 홀수면 1, 아니면 0을 저장하도록 했다. (9번 줄)
그러면, 리프노드에서 상위노드로 올라갈 때 그 구간의 홀수 개수를 저장한다.
arr의 숫자가 변경되면, 원래 있던 숫자가 홀수인지 짝수인지 여부를 검사하고 홀수에서 홀수, 짝수로 변하거나 짝수에서 홀수, 짝수로 변할때
tree[node]의 값이 그대로이거나 +1 또는 -1 될 수 있으므로 그때마다 update 하도록 했다. (43 ~ 46번 줄)
*/
