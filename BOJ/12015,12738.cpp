#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6 + 1;
pair<int,int> p[SIZE];
vector<int> tree(SIZE*4);
int n;

int update(int node, int s, int e, int idx, int k)
{
    if(idx<s || idx>e) return tree[node];
    if(s==e) return tree[node] = k;
    int m = (s+e) / 2;
    return tree[node] = max(update(node*2, s, m, idx, k), update(node*2+1, m+1, e, idx, k));
}

int query(int node, int s, int e, int l, int r)
{
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[node];
    int m = (s+e)/2;
    return max(query(node*2, s, m, l, r), query(node*2+1, m+1, e, l, r));
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p+1,p+n+1,[](pair<int,int> p1, pair<int,int> p2){
         if(p1.first != p2.first) return p1.first < p2.first;
         return p1.second > p2.second;
    });

    for(int i=1 ; i<=n ; i++){
        int val = query(1, 1, SIZE, 1, p[i].second) + 1; // 처음 인덱스 ~ 들어오는값의 인덱스 - 1 까지의 LIS
        update(1, 1, SIZE, p[i].second, val);
    }
    cout << tree[1];
    return 0;
}

/*
kks227님의 블로그를 참조했다. https://m.blog.naver.com/kks227/220791986409
두 문제 다 동일한 코드로 풀린다. ㅋㅋ 제한 크기는 100만으로 같고 들어가는 값의 범위만 음수부분이 추가됐을 뿐이다.
들어오는 값마다 LIS를 업데이트 해주는데, 이전의 값에 대해 정렬을 시켜놓고 원래 값의 인덱스값만 업데이트 시켜주면 된다.
*/
