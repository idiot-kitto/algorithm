#include <bits/stdc++.h>
using namespace std;
int n, ans, tree[80001], lazy[80001];
pair<int,int> p[10001];
vector<int> v;

void update_lazy(int node, int s, int e)
{
    if(!lazy[node]) return;
    tree[node] = e - s + 1;
    if(s!=e){
        lazy[node*2] = 1;
        lazy[node*2+1] = 1;
    }
    lazy[node] = 0;
}

void update_range(int node, int s, int e, int l, int r)
{
    update_lazy(node, s, e);
    if(l>e || r<s) return;
    if(l<=s && e<=r){
        lazy[node] = 1;
        update_lazy(node, s, e);
        return;
    }
    int m = (s+e) / 2;
    update_range(node*2, s, m, l, r);
    update_range(node*2+1, m+1, e, l, r);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int s, int e, int l, int r)
{
    update_lazy(node, s, e);
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[node];
    int m = (s+e) / 2;
    return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> p[i].first >> p[i].second;
        v.push_back(p[i].first);
        v.push_back(p[i].second);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=n-1 ; i>=0 ; i--){
        int a = lower_bound(v.begin(),v.end(),p[i].first) - v.begin() + 1;
        int b = lower_bound(v.begin(),v.end(),p[i].second) - v.begin() + 1;
        int val = query(1, 1, n*2, a, b);
        if(val != b-a+1) ans++;
        update_range(1, 1, n*2, a, b);
    }
    cout << ans;
    return 0;
}

/*
포스터의 위치가 1 부터 100,000,000 까지이다. 그래서 1억개의 int형 배열이면, 4byte * 100,000,000 / 1024 / 1024 는 약 381MB가 나오기 때문에 
문제의 메모리 제한 192MB를 훨씬 넘어가므로 좌표 압축 방법을 사용했다.
입력으로 주어지는 포스터가 붙는 위치를 벡터에 담고, 정렬 후 중복을 제거(v.erase(unique(v.begin(),v.end()), v.end());)했다.
그리고 이 위치들에 대해 순서대로 인덱스를 부여해 이 인덱스들을 트리노드의 인덱스로 이용해 문제를 풀 수 있다.
풀면서 실수했던 부분은 query나 update_range의 값을 계속 n 으로 해주었던 부분이다.
문제에 나온 테스트케이스로 예를 들면, {1,4}, {2,6}, {8,10}, {3,4}, {7,10} 이 들어오고 중복을 제거하면 1(1), 2(2), 3(3), 4(4), 6(5), 7(6), 8(7), 10(8) (괄호 안은 인덱스)가
벡터에 들어가기 때문에 query와 update_range 는 1 부터 n*2 까지의 공간 사이에서 따져줘야 한다.
*/
