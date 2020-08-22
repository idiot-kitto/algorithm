#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end)
{
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(arr, tree, node*2, start, mid) + init(arr, tree, node*2+1, mid+1, end);
}
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int h = (int)ceil(log2(n));
    int tree_size = (1<<(h+1));
    vector<ll> arr(n);
    vector<ll> tree(tree_size);
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    init(arr, tree, 1, 0, n-1);

    while(m--){
        int left, right;
        cin >> left >> right;
        cout << sum(tree, 1, 0, n-1, left-1, right-1) << "\n";
    }
    return 0;
}
